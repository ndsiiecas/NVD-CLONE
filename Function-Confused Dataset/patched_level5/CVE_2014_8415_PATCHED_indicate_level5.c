static int CVE_2014_8415_PATCHED_indicate(void *data)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	pjsip_tx_data *packet = NULL;
	struct indicate_data *ind_data = data;
	struct ast_sip_session *session = ind_data->session;
	int response_code = ind_data->response_code;

	if ((session->inv_session->state != PJSIP_INV_STATE_DISCONNECTED) &&
		(pjsip_inv_answer(session->inv_session, response_code, NULL, NULL, &packet) == PJ_SUCCESS)) {
		ast_sip_session_send_response(session, packet);
	}

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	ao2_ref(ind_data, -1);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);

	return 0;
}
