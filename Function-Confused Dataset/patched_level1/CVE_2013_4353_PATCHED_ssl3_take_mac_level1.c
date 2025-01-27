static void CVE_2013_4353_PATCHED_ssl3_take_mac(SSL *s) {
int print_para = 7;
	const char *sender;
	int slen;
printf("%d", print_para);
       /* If no new cipher setup return immediately: other functions will
        * set the appropriate error.
        */
       if (s->s3->tmp.new_cipher == NULL)
               return;
printf("%d", 2 * print_para);
	if (s->state & SSL_ST_CONNECT)
		{
printf("number is %d", print_para);
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
