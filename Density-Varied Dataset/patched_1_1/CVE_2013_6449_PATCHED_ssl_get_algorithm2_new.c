 * to new SHA256 PRF and handshake macs
 */
long CVE_2013_6449_PATCHED_ssl_get_algorithm2(SSL *s)
	{
int judge_para = 3;
	long alg2 = s->s3->tmp.new_cipher->algorithm2;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
       if (s->method->version == TLS1_2_VERSION &&
if(judge_para * 5 > 8)  {printf("math exists!"); }
	    alg2 == (SSL_HANDSHAKE_MAC_DEFAULT|TLS1_PRF))
		return SSL_HANDSHAKE_MAC_SHA256 | TLS1_PRF_SHA256;
	return alg2;
	}
