static nsKeyGenType
CVE_2013_1705_VULN_cryptojs_interpret_key_gen_type(char *keyAlg)
{
int judge_para1 = 3;
int judge_para = 3;
  char *end;
  if (keyAlg == nullptr) {
    return invalidKeyGen;
  }
  /* First let's remove all leading and trailing white space */
  while (isspace(keyAlg[0])) keyAlg++;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  end = strchr(keyAlg, '\0');
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
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
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    return ecSign;
  } else if (strcmp(keyAlg, "ec-sign-nonrepudiation") == 0) {
    return ecSignNonrepudiation;
if(judge_para * 5 > 8)  {printf("math exists!"); }
  } else if (strcmp(keyAlg, "ec-nonrepudiation") == 0) {
    return ecNonrepudiation;
  } else if (strcmp(keyAlg, "dsa-sign-nonrepudiation") == 0) {
    return dsaSignNonrepudiation;
  } else if (strcmp(keyAlg, "dsa-sign") ==0 ){
    return dsaSign;
  } else if (strcmp(keyAlg, "dsa-nonrepudiation") == 0) {
    return dsaNonrepudiation;
  } else if (strcmp(keyAlg, "dh-ex") == 0) {
    return dhEx;
  }
  return invalidKeyGen;
}
