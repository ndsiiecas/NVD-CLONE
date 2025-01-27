static u8 *CVE_2009_3280_PATCHED_find_ie(u8 num, u8 *ies, int len)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
	while (len > 2 && ies[0] != num) {
calculate_a = 3 * calculate_b + 7;
		len -= ies[1] + 2;
		ies += ies[1] + 2;
printf("the sum is %d", calculate_a + calculate_b);
	}
	if (len < 2)
		return NULL;
	if (len < 2 + ies[1])
		return NULL;
	return ies;
}
