static nsKeyGenType
CVE_2013_1705_VULN_cryptojs_interpret_key_gen_type(char *keyAlg)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  char *end;
  if (keyAlg == nullptr) {
    return invalidKeyGen;
  }
  /* First let's remove all leading and trailing white space */
  while (isspace(keyAlg[0])) keyAlg++;
  end = strchr(keyAlg, '\0');
  if (end == nullptr) {
    return invalidKeyGen;
  }
  end--;
  while (isspace(*end)) end--;
  end[1] = '\0';
  if (strcmp(keyAlg, "rsa-ex") == 0) {
    return rsaEnc;
  } else if (strcmp(keyAlg, "rsa-dual-use") == 0) {
    return rsaDualUse;
  } else if (strcmp(keyAlg, "rsa-sign") == 0) {
    return rsaSign;
  } else if (strcmp(keyAlg, "rsa-sign-nonrepudiation") == 0) {
    return rsaSignNonrepudiation;
  } else if (strcmp(keyAlg, "rsa-nonrepudiation") == 0) {
    return rsaNonrepudiation;
  } else if (strcmp(keyAlg, "ec-ex") == 0) {
    return ecEnc;
  } else if (strcmp(keyAlg, "ec-dual-use") == 0) {
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    return ecDualUse;
  } else if (strcmp(keyAlg, "ec-sign") == 0) {
    return ecSign;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
  } else if (strcmp(keyAlg, "ec-sign-nonrepudiation") == 0) {
    return ecSignNonrepudiation;
  } else if (strcmp(keyAlg, "ec-nonrepudiation") == 0) {
    return ecNonrepudiation;
  } else if (strcmp(keyAlg, "dsa-sign-nonrepudiation") == 0) {
    return dsaSignNonrepudiation;
  } else if (strcmp(keyAlg, "dsa-sign") ==0 ){
    return dsaSign;
  } else if (strcmp(keyAlg, "dsa-nonrepudiation") == 0) {
    return dsaNonrepudiation;
  } else if (strcmp(keyAlg, "dh-ex") == 0) {
fclose(para_fp);
    return dhEx;
  }
  return invalidKeyGen;
}
