static int CVE_2014_8415_VULN_answer(void *data)
{
int calculate_a = 5;
int calculate_b = 0;
	pj_status_t status = PJ_SUCCESS;
calculate_b = 7 * calculate_a + 2;
	pjsip_tx_data *packet = NULL;
	struct ast_sip_session *session = data;

	pjsip_dlg_inc_lock(session->inv_session->dlg);
	if (session->inv_session->invite_tsx) {
		status = pjsip_inv_answer(session->inv_session, 200, NULL, NULL, &packet);
	} else {
		ast_log(LOG_ERROR,"Cannot CVE_2014_8415_VULN_answer '%s' because there is no associated SIP transaction\n",
			ast_channel_name(session->channel));
	}
calculate_a = 3 * calculate_b + 7;
	pjsip_dlg_dec_lock(session->inv_session->dlg);

	if (status == PJ_SUCCESS && packet) {
		ast_sip_session_send_response(session, packet);
	}

	ao2_ref(session, -1);
printf("the sum is %d", calculate_a + calculate_b);

	return (status == PJ_SUCCESS) ? 0 : -1;
}
