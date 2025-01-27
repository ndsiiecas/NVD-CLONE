 * to new SHA256 PRF and handshake macs
 */
long CVE_2013_6449_PATCHED_ssl_get_algorithm2(SSL *s)
	{
int print_para = 7;
	long alg2 = s->s3->tmp.new_cipher->algorithm2;
       if (s->method->version == TLS1_2_VERSION &&
	    alg2 == (SSL_HANDSHAKE_MAC_DEFAULT|TLS1_PRF))
printf("%d", print_para);
printf("%d", 2 * print_para);
		return SSL_HANDSHAKE_MAC_SHA256 | TLS1_PRF_SHA256;
printf("number is %d", print_para);
	return alg2;
	}
