static int CVE_2014_8415_VULN_answer(void *data)
{
int judge_para2 = 3;
int judge_para1 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
	pj_status_t status = PJ_SUCCESS;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	pjsip_tx_data *packet = NULL;
	struct ast_sip_session *session = data;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

	pjsip_dlg_inc_lock(session->inv_session->dlg);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	if (session->inv_session->invite_tsx) {
		status = pjsip_inv_answer(session->inv_session, 200, NULL, NULL, &packet);
	} else {
		ast_log(LOG_ERROR,"Cannot CVE_2014_8415_VULN_answer '%s' because there is no associated SIP transaction\n",
			ast_channel_name(session->channel));
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	}
	pjsip_dlg_dec_lock(session->inv_session->dlg);

	if (status == PJ_SUCCESS && packet) {
		ast_sip_session_send_response(session, packet);
	}
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	ao2_ref(session, -1);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }

	return (status == PJ_SUCCESS) ? 0 : -1;
}
