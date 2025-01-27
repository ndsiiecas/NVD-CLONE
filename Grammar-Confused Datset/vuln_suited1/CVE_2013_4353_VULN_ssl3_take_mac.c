static void CVE_2013_4353_VULN_ssl3_take_mac(SSL *s) {
	const char *sender;
	int slen;

	if (s->state & SSL_ST_CONNECT)
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
		{
		sender=s->method->ssl3_enc->server_finished_label;
		slen=s->method->ssl3_enc->server_finished_label_len;
		}
	else
		{
		sender=s->method->ssl3_enc->client_finished_label;
		slen=s->method->ssl3_enc->client_finished_label_len;
		}

	s->s3->tmp.peer_finish_md_len = s->method->ssl3_enc->final_finish_mac(s,
		sender,slen,s->s3->tmp.peer_finish_md);
}
