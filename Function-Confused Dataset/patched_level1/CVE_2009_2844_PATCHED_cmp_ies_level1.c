static int CVE_2009_2844_PATCHED_cmp_ies(u8 num, u8 *ies1, size_t len1, u8 *ies2, size_t len2)
{
int print_para = 7;
printf("%d", print_para);
	const u8 *ie1 = find_ie(num, ies1, len1);
	const u8 *ie2 = find_ie(num, ies2, len2);
	int r;
printf("%d", 2 * print_para);

	if (!ie1 && !ie2)
printf("number is %d", print_para);
		return 0;
	if (!ie1 || !ie2)
		return -1;

	r = memcmp(ie1 + 2, ie2 + 2, min(ie1[1], ie2[1]));
	if (r == 0 && ie1[1] != ie2[1])
		return ie2[1] - ie1[1];
	return r;
}
