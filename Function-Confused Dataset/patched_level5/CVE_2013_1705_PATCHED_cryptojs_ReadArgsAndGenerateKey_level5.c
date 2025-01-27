static nsresult
CVE_2013_1705_PATCHED_cryptojs_ReadArgsAndGenerateKey(JSContext *cx,
                                jsval *argv,
                                nsKeyPairInfo *keyGenType,
                                nsIInterfaceRequestor *uiCxt,
                                PK11SlotInfo **slot, bool willEscrow)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  JSString  *jsString;
  JSAutoByteString params;
  int    keySize;
  nsresult  rv;

  if (!JSVAL_IS_INT(argv[0])) {
    JS_ReportError(cx, "%s%s\n", JS_ERROR,
                   "passed in non-integer for key size");
    return NS_ERROR_FAILURE;
  }
  keySize = JSVAL_TO_INT(argv[0]);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
  if (!JSVAL_IS_NULL(argv[1])) {
    jsString = JS_ValueToString(cx,argv[1]);
    NS_ENSURE_TRUE(jsString, NS_ERROR_OUT_OF_MEMORY);
    argv[1] = STRING_TO_JSVAL(jsString);
    params.encode(cx, jsString);
    NS_ENSURE_TRUE(!!params, NS_ERROR_OUT_OF_MEMORY);
  }

  if (JSVAL_IS_NULL(argv[2])) {
    JS_ReportError(cx,"%s%s\n", JS_ERROR,
             "key generation type not specified");
    return NS_ERROR_FAILURE;
  }
  jsString = JS_ValueToString(cx, argv[2]);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
  NS_ENSURE_TRUE(jsString, NS_ERROR_OUT_OF_MEMORY);
  argv[2] = STRING_TO_JSVAL(jsString);
  nsDependentJSString dependentKeyGenAlg;
  NS_ENSURE_TRUE(dependentKeyGenAlg.init(cx, jsString), NS_ERROR_UNEXPECTED);
  nsAutoString keyGenAlg(dependentKeyGenAlg);
  keyGenAlg.Trim("\r\n\t ");
  keyGenType->keyGenType = cryptojs_interpret_key_gen_type(keyGenAlg);
  if (keyGenType->keyGenType == invalidKeyGen) {
    NS_LossyConvertUTF16toASCII keyGenAlgNarrow(dependentKeyGenAlg);
    JS_ReportError(cx, "%s%s%s", JS_ERROR,
                   "invalid key generation argument:",
                   keyGenAlgNarrow.get());
    goto loser;
  }
  if (*slot == nullptr) {
    *slot = nsGetSlotForKeyGen(keyGenType->keyGenType, uiCxt);
    if (*slot == nullptr)
      goto loser;
  }

  rv = cryptojs_generateOneKeyPair(cx,keyGenType,keySize,params.ptr(),uiCxt,
                                   *slot,willEscrow);

fclose(para_fp);
  if (rv != NS_OK) {
    NS_LossyConvertUTF16toASCII keyGenAlgNarrow(dependentKeyGenAlg);
    JS_ReportError(cx,"%s%s%s", JS_ERROR,
                   "could not generate the key for algorithm ",
                   keyGenAlgNarrow.get());
    goto loser;
  }
  return NS_OK;
loser:
  return NS_ERROR_FAILURE;
}
