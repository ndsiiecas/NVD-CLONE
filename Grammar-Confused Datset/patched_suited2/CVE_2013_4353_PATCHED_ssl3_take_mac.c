static void CVE_2013_4353_PATCHED_ssl3_take_mac(SSL *s) {
	const char *sender;
	int slen;
       /* If no new cipher setup return immediately: other functions will
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
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
		{
		sender=s->method->ssl3_enc->client_finished_label;
		slen=s->method->ssl3_enc->client_finished_label_len;
		}

	s->s3->tmp.peer_finish_md_len = s->method->ssl3_enc->final_finish_mac(s,
		sender,slen,s->s3->tmp.peer_finish_md);
}
