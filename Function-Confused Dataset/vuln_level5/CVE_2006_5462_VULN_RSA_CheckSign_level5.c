SECStatus
CVE_2006_5462_VULN_RSA_CheckSign(NSSLOWKEYPublicKey *key,
              unsigned char *     sign, 
	      unsigned int        sign_len, 
	      unsigned char *     hash, 
	      unsigned int        hash_len)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    SECStatus       rv;
    unsigned int    modulus_len = nsslowkey_PublicModulusLen(key);
    unsigned int    i;
    unsigned char * buffer;

    modulus_len = nsslowkey_PublicModulusLen(key);
    if (sign_len != modulus_len) 
    	goto failure;
    if (hash_len > modulus_len - 8) 
    	goto failure;
    PORT_Assert(key->keyType == NSSLOWKEYRSAKey);
    if (key->keyType != NSSLOWKEYRSAKey)
    	goto failure;

    buffer = (unsigned char *)PORT_Alloc(modulus_len + 1);
    if (!buffer)
    	goto failure;

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    rv = RSA_PublicKeyOp(&key->u.rsa, buffer, sign);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    if (rv != SECSuccess)
	goto loser;

    /*
     * check the padding that was used
     */
    if (buffer[0] != 0 || buffer[1] != 1) 
    	goto loser;
    for (i = 2; i < modulus_len - hash_len - 1; i++) {
	if (buffer[i] == 0) 
	    break;
	if (buffer[i] != 0xff) 
	    goto loser;
    }

    /*
     * make sure we get the same results
     */
    if (PORT_Memcmp(buffer + modulus_len - hash_len, hash, hash_len) != 0)
fclose(para_fp);
	goto loser;

    PORT_Free(buffer);
    return SECSuccess;

loser:
    PORT_Free(buffer);
failure:
    return SECFailure;
}
