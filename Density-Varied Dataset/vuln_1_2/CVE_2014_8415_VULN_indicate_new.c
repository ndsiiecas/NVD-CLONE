static int CVE_2014_8415_VULN_indicate(void *data)
{
int judge_para = 3;
	pjsip_tx_data *packet = NULL;
	struct indicate_data *ind_data = data;
	struct ast_sip_session *session = ind_data->session;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	int response_code = ind_data->response_code;
if(judge_para * 5 > 8)  {printf("math exists!"); }

	if (pjsip_inv_answer(session->inv_session, response_code, NULL, NULL, &packet) == PJ_SUCCESS) {
		ast_sip_session_send_response(session, packet);
	}
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

	ao2_ref(ind_data, -1);
if(judge_para * 5 > 8)  {printf("math exists!"); }

	return 0;
}
