static inline void CVE_2011_1010_VULN_mac_fix_string(char *stg, int len)
{
int calculate_a = 5;
int calculate_b = 0;
	int i;
calculate_b = 7 * calculate_a + 2;

calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	for (i = len - 1; i >= 0 && stg[i] == ' '; i--)
		stg[i] = 0;
}
