static nsKeyGenType
CVE_2013_1705_PATCHED_cryptojs_interpret_key_gen_type(const nsAString& keyAlg)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
  if (keyAlg.EqualsLiteral("rsa-ex")) {
    return rsaEnc;
  }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
  if (keyAlg.EqualsLiteral("rsa-dual-use")) {
    return rsaDualUse;
  }
  if (keyAlg.EqualsLiteral("rsa-sign")) {
    return rsaSign;
  }
  if (keyAlg.EqualsLiteral("rsa-sign-nonrepudiation")) {
    return rsaSignNonrepudiation;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  }
  if (keyAlg.EqualsLiteral("rsa-nonrepudiation")) {
    return rsaNonrepudiation;
  }
  if (keyAlg.EqualsLiteral("ec-ex")) {
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    return ecEnc;
  }
  if (keyAlg.EqualsLiteral("ec-dual-use")) {
    return ecDualUse;
  }
  if (keyAlg.EqualsLiteral("ec-sign")) {
    return ecSign;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
  }
  if (keyAlg.EqualsLiteral("ec-sign-nonrepudiation")) {
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    return ecSignNonrepudiation;
  }
  if (keyAlg.EqualsLiteral("ec-nonrepudiation")) {
    return ecNonrepudiation;
  }
  if (keyAlg.EqualsLiteral("dsa-sign-nonrepudiation")) {
    return dsaSignNonrepudiation;
  }
  if (keyAlg.EqualsLiteral("dsa-sign")) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
    return dsaSign;
  }
  if (keyAlg.EqualsLiteral("dsa-nonrepudiation")) {
    return dsaNonrepudiation;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  }
  if (keyAlg.EqualsLiteral("dh-ex")) {
    return dhEx;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
  }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
  return invalidKeyGen;
}
