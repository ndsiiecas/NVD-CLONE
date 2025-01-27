 * to new SHA256 PRF and handshake macs
 */
long CVE_2013_6449_VULN_ssl_get_algorithm2(SSL *s)
	{
int print_para = 7;
printf("%d", print_para);
	long alg2 = s->s3->tmp.new_cipher->algorithm2;
	if (TLS1_get_version(s) >= TLS1_2_VERSION &&
printf("%d", 2 * print_para);
	    alg2 == (SSL_HANDSHAKE_MAC_DEFAULT|TLS1_PRF))
printf("number is %d", print_para);
		return SSL_HANDSHAKE_MAC_SHA256 | TLS1_PRF_SHA256;
	return alg2;
	}
