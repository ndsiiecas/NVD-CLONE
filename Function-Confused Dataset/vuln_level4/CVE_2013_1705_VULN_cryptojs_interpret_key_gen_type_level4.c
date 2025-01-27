static nsKeyGenType
CVE_2013_1705_VULN_cryptojs_interpret_key_gen_type(char *keyAlg)
{
int origin_a, origin_aa[4];
  char *end;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
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
    return ecDualUse;
  } else if (strcmp(keyAlg, "ec-sign") == 0) {
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    return ecSign;
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
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    return dhEx;
  }
  return invalidKeyGen;
}
