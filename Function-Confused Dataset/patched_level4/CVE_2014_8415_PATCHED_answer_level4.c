static int CVE_2014_8415_PATCHED_answer(void *data)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	pj_status_t status = PJ_SUCCESS;
	pjsip_tx_data *packet = NULL;
	struct ast_sip_session *session = data;

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
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
		ast_sip_session_send_response(session, packet);
	}

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	ao2_ref(session, -1);

	return (status == PJ_SUCCESS) ? 0 : -1;
}
