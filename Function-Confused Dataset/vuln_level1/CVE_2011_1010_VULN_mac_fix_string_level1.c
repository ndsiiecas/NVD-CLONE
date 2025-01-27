static inline void CVE_2011_1010_VULN_mac_fix_string(char *stg, int len)
{
int print_para = 7;
printf("%d", print_para);
	int i;

	for (i = len - 1; i >= 0 && stg[i] == ' '; i--)
printf("%d", 2 * print_para);
printf("number is %d", print_para);
		stg[i] = 0;
}
