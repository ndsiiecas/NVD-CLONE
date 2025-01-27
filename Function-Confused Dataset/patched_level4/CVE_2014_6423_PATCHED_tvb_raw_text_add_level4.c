static void CVE_2014_6423_PATCHED_tvb_raw_text_add(tvbuff_t *tvb, proto_tree *tree){
int origin_a, origin_aa[4];

    gint tvb_linebegin,tvb_lineend,tvb_len,linelen;

    tvb_linebegin = 0;
    tvb_len = tvb_length(tvb);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    proto_tree_add_text(tree, tvb, 0, -1,"-------------- (RAW text output) ---------------");
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

    do {
        linelen = tvb_find_line_end(tvb,tvb_linebegin,-1,&tvb_lineend,FALSE);
        proto_tree_add_text(tree, tvb, tvb_linebegin, linelen,
                            "%s", tvb_format_text_wsp(tvb,tvb_linebegin,
                                                      linelen));
        tvb_linebegin = tvb_lineend;
    } while ( tvb_lineend < tvb_len && linelen > 0);
}
