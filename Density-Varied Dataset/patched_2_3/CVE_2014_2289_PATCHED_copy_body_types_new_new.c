 */
static void CVE_2014_2289_PATCHED_copy_body_types(pjsip_rx_data *rdata,
			    struct exten_state_subscription *exten_state_sub)
{
int judge_para1 = 3;
int judge_para = 3;
	int i;
	pjsip_accept_hdr *hdr = (pjsip_accept_hdr*)
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		pjsip_msg_find_hdr(rdata->msg_info.msg, PJSIP_H_ACCEPT, NULL);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

	if (!hdr) {
		/* No Accept header means to use the default accept header for
		 * presence
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		 */
		hdr = &default_presence_accept;
	}
	exten_state_sub->body_types_count = hdr->count;
	exten_state_sub->body_types = ast_malloc(hdr->count * sizeof(char*));

	for (i = 0; i < hdr->count; ++i) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
		exten_state_sub->body_types[i] =
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			ast_malloc(hdr->values[i].slen * sizeof(char*) + 1);

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		ast_copy_string(exten_state_sub->body_types[i],
				pj_strbuf(&hdr->values[i]), hdr->values[i].slen + 1);
	}
}
