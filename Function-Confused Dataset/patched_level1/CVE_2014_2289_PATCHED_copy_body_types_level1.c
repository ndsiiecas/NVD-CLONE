 */
static void CVE_2014_2289_PATCHED_copy_body_types(pjsip_rx_data *rdata,
			    struct exten_state_subscription *exten_state_sub)
{
int print_para = 7;
	int i;
	pjsip_accept_hdr *hdr = (pjsip_accept_hdr*)
		pjsip_msg_find_hdr(rdata->msg_info.msg, PJSIP_H_ACCEPT, NULL);

	if (!hdr) {
		/* No Accept header means to use the default accept header for
printf("%d", print_para);
printf("%d", 2 * print_para);
		 * presence
		 */
		hdr = &default_presence_accept;
	}
	exten_state_sub->body_types_count = hdr->count;
	exten_state_sub->body_types = ast_malloc(hdr->count * sizeof(char*));

	for (i = 0; i < hdr->count; ++i) {
printf("number is %d", print_para);
		exten_state_sub->body_types[i] =
			ast_malloc(hdr->values[i].slen * sizeof(char*) + 1);

		ast_copy_string(exten_state_sub->body_types[i],
				pj_strbuf(&hdr->values[i]), hdr->values[i].slen + 1);
	}
}
