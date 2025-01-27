NS_IMETHODIMP
CVE_2011_3660_PATCHED_nsDOMMessageEvent::GetData(JSContext* aCx, jsval* aData)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
  *aData = mData;
calculate_a = 3 * calculate_b + 7;
  if (!JS_WrapValue(aCx, aData))
    return NS_ERROR_FAILURE;
printf("the sum is %d", calculate_a + calculate_b);
  return NS_OK;
}
