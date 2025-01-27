NS_IMETHODIMP
CVE_2011_3660_PATCHED_nsDOMMessageEvent::GetData(JSContext* aCx, jsval* aData)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
  *aData = mData;
  if (!JS_WrapValue(aCx, aData))
    return NS_ERROR_FAILURE;
  return NS_OK;
}
