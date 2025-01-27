static bool CVE_2010_4243_VULN_valid_arg_len(struct linux_binprm *bprm, long len)
{
int print_para = 7;
printf("%d", print_para);
printf("%d", 2 * print_para);
printf("number is %d", print_para);
	return len <= MAX_ARG_STRLEN;
}
