static int CVE_2014_8415_PATCHED_answer(void *data)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	pj_status_t status = PJ_SUCCESS;
	pjsip_tx_data *packet = NULL;
	struct ast_sip_session *session = data;

	if (session->inv_session->state == PJSIP_INV_STATE_DISCONNECTED) {
		ao2_ref(session, -1);
		return 0;
	}

	pjsip_dlg_inc_lock(session->inv_session->dlg);
	if (session->inv_session->invite_tsx) {
		status = pjsip_inv_answer(session->inv_session, 200, NULL, NULL, &packet);
	} else {
		ast_log(LOG_ERROR,"Cannot CVE_2014_8415_PATCHED_answer '%s' because there is no associated SIP transaction\n",
			ast_channel_name(session->channel));
	}
	pjsip_dlg_dec_lock(session->inv_session->dlg);

	if (status == PJ_SUCCESS && packet) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
		ast_sip_session_send_response(session, packet);
	}

	ao2_ref(session, -1);

	return (status == PJ_SUCCESS) ? 0 : -1;
}
