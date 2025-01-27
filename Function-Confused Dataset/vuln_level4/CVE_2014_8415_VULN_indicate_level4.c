static int CVE_2014_8415_VULN_indicate(void *data)
{
int origin_a, origin_aa[4];
	pjsip_tx_data *packet = NULL;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	struct indicate_data *ind_data = data;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	struct ast_sip_session *session = ind_data->session;
	int response_code = ind_data->response_code;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

	if (pjsip_inv_answer(session->inv_session, response_code, NULL, NULL, &packet) == PJ_SUCCESS) {
		ast_sip_session_send_response(session, packet);
	}

	ao2_ref(ind_data, -1);

	return 0;
}
