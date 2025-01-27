static int CVE_2014_8415_PATCHED_answer(void *data)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	pj_status_t status = PJ_SUCCESS;
	pjsip_tx_data *packet = NULL;
	struct ast_sip_session *session = data;

	if (session->inv_session->state == PJSIP_INV_STATE_DISCONNECTED) {
		ao2_ref(session, -1);
		return 0;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	}

	pjsip_dlg_inc_lock(session->inv_session->dlg);
	if (session->inv_session->invite_tsx) {
		status = pjsip_inv_answer(session->inv_session, 200, NULL, NULL, &packet);
	} else {
		ast_log(LOG_ERROR,"Cannot CVE_2014_8415_PATCHED_answer '%s' because there is no associated SIP transaction\n",
			ast_channel_name(session->channel));
	}
	pjsip_dlg_dec_lock(session->inv_session->dlg);

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	if (status == PJ_SUCCESS && packet) {
		ast_sip_session_send_response(session, packet);
	}

	ao2_ref(session, -1);
fclose(para_fp);

	return (status == PJ_SUCCESS) ? 0 : -1;
}
