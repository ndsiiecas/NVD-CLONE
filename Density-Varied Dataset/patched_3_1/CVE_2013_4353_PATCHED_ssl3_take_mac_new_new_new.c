static void CVE_2013_4353_PATCHED_ssl3_take_mac(SSL *s) {
int judge_para2 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para1 = 3;
int judge_para = 3;
	const char *sender;
	int slen;
       /* If no new cipher setup return immediately: other functions will
        * set the appropriate error.
        */
       if (s->s3->tmp.new_cipher == NULL)
               return;
	if (s->state & SSL_ST_CONNECT)
		{
		sender=s->method->ssl3_enc->server_finished_label;
		slen=s->method->ssl3_enc->server_finished_label_len;
		}
	else
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		{
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		sender=s->method->ssl3_enc->client_finished_label;
		slen=s->method->ssl3_enc->client_finished_label_len;
		}
if(judge_para * 5 > 8)  {printf("math exists!"); }

	s->s3->tmp.peer_finish_md_len = s->method->ssl3_enc->final_finish_mac(s,
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		sender,slen,s->s3->tmp.peer_finish_md);
}
