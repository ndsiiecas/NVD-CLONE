NS_IMETHODIMP
CVE_2011_3660_PATCHED_nsDOMMessageEvent::GetData(JSContext* aCx, jsval* aData)
{
int print_para = 7;
printf("%d", print_para);
  *aData = mData;
printf("%d", 2 * print_para);
printf("number is %d", print_para);
  if (!JS_WrapValue(aCx, aData))
    return NS_ERROR_FAILURE;
  return NS_OK;
}
