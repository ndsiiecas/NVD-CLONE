static u8 *CVE_2009_3280_PATCHED_find_ie(u8 num, u8 *ies, int len)
{
int print_para = 7;
printf("%d", print_para);
	while (len > 2 && ies[0] != num) {
printf("%d", 2 * print_para);
		len -= ies[1] + 2;
printf("number is %d", print_para);
		ies += ies[1] + 2;
	}
	if (len < 2)
		return NULL;
	if (len < 2 + ies[1])
		return NULL;
	return ies;
}
