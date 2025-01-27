static int CVE_2014_8415_PATCHED_indicate(void *data)
{
	pjsip_tx_data *packet = NULL;
	struct indicate_data *ind_data = data;
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	struct ast_sip_session *session = ind_data->session;
	int response_code = ind_data->response_code;

	if ((session->inv_session->state != PJSIP_INV_STATE_DISCONNECTED) &&
		(pjsip_inv_answer(session->inv_session, response_code, NULL, NULL, &packet) == PJ_SUCCESS)) {
		ast_sip_session_send_response(session, packet);
	}

	ao2_ref(ind_data, -1);

	return 0;
}
