static nsKeyGenType
CVE_2013_1705_PATCHED_cryptojs_interpret_key_gen_type(const nsAString& keyAlg)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  if (keyAlg.EqualsLiteral("rsa-ex")) {
    return rsaEnc;
  }
  if (keyAlg.EqualsLiteral("rsa-dual-use")) {
    return rsaDualUse;
  }
  if (keyAlg.EqualsLiteral("rsa-sign")) {
    return rsaSign;
  }
  if (keyAlg.EqualsLiteral("rsa-sign-nonrepudiation")) {
    return rsaSignNonrepudiation;
  }
  if (keyAlg.EqualsLiteral("rsa-nonrepudiation")) {
    return rsaNonrepudiation;
  }
  if (keyAlg.EqualsLiteral("ec-ex")) {
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    return ecEnc;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
  }
  if (keyAlg.EqualsLiteral("ec-dual-use")) {
    return ecDualUse;
  }
  if (keyAlg.EqualsLiteral("ec-sign")) {
    return ecSign;
  }
  if (keyAlg.EqualsLiteral("ec-sign-nonrepudiation")) {
    return ecSignNonrepudiation;
  }
  if (keyAlg.EqualsLiteral("ec-nonrepudiation")) {
    return ecNonrepudiation;
  }
  if (keyAlg.EqualsLiteral("dsa-sign-nonrepudiation")) {
    return dsaSignNonrepudiation;
  }
  if (keyAlg.EqualsLiteral("dsa-sign")) {
    return dsaSign;
  }
  if (keyAlg.EqualsLiteral("dsa-nonrepudiation")) {
    return dsaNonrepudiation;
  }
  if (keyAlg.EqualsLiteral("dh-ex")) {
    return dhEx;
  }
fclose(para_fp);
  return invalidKeyGen;
}
