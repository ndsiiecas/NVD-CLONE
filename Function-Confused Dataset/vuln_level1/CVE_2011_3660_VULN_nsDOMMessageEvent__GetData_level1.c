NS_IMETHODIMP
CVE_2011_3660_VULN_nsDOMMessageEvent::GetData(jsval* aData)
{
int print_para = 7;
printf("%d", print_para);
printf("%d", 2 * print_para);
  *aData = mData;
printf("number is %d", print_para);
  return NS_OK;
}
