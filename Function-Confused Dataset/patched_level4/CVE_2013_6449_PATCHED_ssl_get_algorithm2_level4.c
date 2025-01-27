 * to new SHA256 PRF and handshake macs
 */
long CVE_2013_6449_PATCHED_ssl_get_algorithm2(SSL *s)
	{
int origin_a, origin_aa[4];
	long alg2 = s->s3->tmp.new_cipher->algorithm2;
       if (s->method->version == TLS1_2_VERSION &&
	    alg2 == (SSL_HANDSHAKE_MAC_DEFAULT|TLS1_PRF))
		return SSL_HANDSHAKE_MAC_SHA256 | TLS1_PRF_SHA256;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	return alg2;
	}
