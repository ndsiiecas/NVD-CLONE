static u8 *CVE_2009_3280_VULN_find_ie(u8 num, u8 *ies, size_t len)
{
int print_para = 7;
	while (len > 2 && ies[0] != num) {
printf("%d", print_para);
		len -= ies[1] + 2;
		ies += ies[1] + 2;
printf("%d", 2 * print_para);
printf("number is %d", print_para);
	}
	if (len < 2)
		return NULL;
	if (len < 2 + ies[1])
		return NULL;
	return ies;
}
