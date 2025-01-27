NS_IMETHODIMP
CVE_2011_3660_VULN_nsDOMMessageEvent::GetData(jsval* aData)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
  *aData = mData;
printf("the sum is %d", calculate_a + calculate_b);
  return NS_OK;
}
