static u8 *CVE_2009_3280_VULN_find_ie(u8 num, u8 *ies, size_t len)
{
int calculate_a = 5;
int calculate_b = 0;
	while (len > 2 && ies[0] != num) {
		len -= ies[1] + 2;
calculate_b = 7 * calculate_a + 2;
		ies += ies[1] + 2;
calculate_a = 3 * calculate_b + 7;
	}
	if (len < 2)
		return NULL;
	if (len < 2 + ies[1])
		return NULL;
printf("the sum is %d", calculate_a + calculate_b);
	return ies;
}
