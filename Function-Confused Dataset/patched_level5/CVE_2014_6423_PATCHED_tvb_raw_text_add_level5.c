static void CVE_2014_6423_PATCHED_tvb_raw_text_add(tvbuff_t *tvb, proto_tree *tree){
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    gint tvb_linebegin,tvb_lineend,tvb_len,linelen;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

fclose(para_fp);
    tvb_linebegin = 0;
    tvb_len = tvb_length(tvb);

    proto_tree_add_text(tree, tvb, 0, -1,"-------------- (RAW text output) ---------------");

    do {
        linelen = tvb_find_line_end(tvb,tvb_linebegin,-1,&tvb_lineend,FALSE);
        proto_tree_add_text(tree, tvb, tvb_linebegin, linelen,
                            "%s", tvb_format_text_wsp(tvb,tvb_linebegin,
                                                      linelen));
        tvb_linebegin = tvb_lineend;
    } while ( tvb_lineend < tvb_len && linelen > 0);
}
