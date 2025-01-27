static int CVE_2014_8415_PATCHED_indicate(void *data)
{
int print_para = 7;
	pjsip_tx_data *packet = NULL;
	struct indicate_data *ind_data = data;
printf("%d", print_para);
	struct ast_sip_session *session = ind_data->session;
	int response_code = ind_data->response_code;
printf("%d", 2 * print_para);

	if ((session->inv_session->state != PJSIP_INV_STATE_DISCONNECTED) &&
		(pjsip_inv_answer(session->inv_session, response_code, NULL, NULL, &packet) == PJ_SUCCESS)) {
		ast_sip_session_send_response(session, packet);
	}

printf("number is %d", print_para);
	ao2_ref(ind_data, -1);

	return 0;
}
