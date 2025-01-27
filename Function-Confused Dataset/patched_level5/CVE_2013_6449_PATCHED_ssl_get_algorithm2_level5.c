 * to new SHA256 PRF and handshake macs
 */
long CVE_2013_6449_PATCHED_ssl_get_algorithm2(SSL *s)
	{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	long alg2 = s->s3->tmp.new_cipher->algorithm2;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
       if (s->method->version == TLS1_2_VERSION &&
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	    alg2 == (SSL_HANDSHAKE_MAC_DEFAULT|TLS1_PRF))
		return SSL_HANDSHAKE_MAC_SHA256 | TLS1_PRF_SHA256;
fclose(para_fp);
	return alg2;
	}
