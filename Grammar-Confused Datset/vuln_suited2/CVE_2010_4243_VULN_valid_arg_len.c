static bool CVE_2010_4243_VULN_valid_arg_len(struct linux_binprm *bprm, long len)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	return len <= MAX_ARG_STRLEN;
}
