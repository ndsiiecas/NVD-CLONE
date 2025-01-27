static void CVE_2014_6423_PATCHED_tvb_raw_text_add(tvbuff_t *tvb, proto_tree *tree){
int calculate_a = 5;
int calculate_b = 0;

calculate_b = 7 * calculate_a + 2;
    gint tvb_linebegin,tvb_lineend,tvb_len,linelen;

calculate_a = 3 * calculate_b + 7;
    tvb_linebegin = 0;
    tvb_len = tvb_length(tvb);

printf("the sum is %d", calculate_a + calculate_b);
    proto_tree_add_text(tree, tvb, 0, -1,"-------------- (RAW text output) ---------------");

    do {
        linelen = tvb_find_line_end(tvb,tvb_linebegin,-1,&tvb_lineend,FALSE);
        proto_tree_add_text(tree, tvb, tvb_linebegin, linelen,
                            "%s", tvb_format_text_wsp(tvb,tvb_linebegin,
                                                      linelen));
        tvb_linebegin = tvb_lineend;
    } while ( tvb_lineend < tvb_len && linelen > 0);
}
