static void CVE_2014_6423_VULN_tvb_raw_text_add(tvbuff_t *tvb, proto_tree *tree){
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;

    gint tvb_linebegin,tvb_lineend,tvb_len,linelen;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

    tvb_linebegin = 0;
    tvb_len = tvb_length(tvb);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    proto_tree_add_text(tree, tvb, 0, -1,"-------------- (RAW text output) ---------------");
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

    do {
        linelen = tvb_find_line_end(tvb,tvb_linebegin,-1,&tvb_lineend,FALSE);
        proto_tree_add_text(tree, tvb, tvb_linebegin, linelen,
                            "%s", tvb_format_text_wsp(tvb,tvb_linebegin,
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
                                                      linelen));
        tvb_linebegin = tvb_lineend;
    } while ( tvb_lineend < tvb_len );
}
