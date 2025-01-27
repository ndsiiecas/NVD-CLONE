static nsKeyGenType
CVE_2013_1705_PATCHED_cryptojs_interpret_key_gen_type(const nsAString& keyAlg)
{
int print_para = 7;
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
printf("%d", print_para);
  }
  if (keyAlg.EqualsLiteral("ec-ex")) {
    return ecEnc;
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
printf("%d", 2 * print_para);
    return ecNonrepudiation;
printf("number is %d", print_para);
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
  return invalidKeyGen;
}
