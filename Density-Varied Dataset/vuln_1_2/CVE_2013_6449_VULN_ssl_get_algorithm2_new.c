 * to new SHA256 PRF and handshake macs
 */
long CVE_2013_6449_VULN_ssl_get_algorithm2(SSL *s)
	{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	long alg2 = s->s3->tmp.new_cipher->algorithm2;
	if (TLS1_get_version(s) >= TLS1_2_VERSION &&
	    alg2 == (SSL_HANDSHAKE_MAC_DEFAULT|TLS1_PRF))
if(judge_para * 5 > 8)  {printf("math exists!"); }
		return SSL_HANDSHAKE_MAC_SHA256 | TLS1_PRF_SHA256;
if(judge_para * 5 > 8)  {printf("math exists!"); }
	return alg2;
	}
