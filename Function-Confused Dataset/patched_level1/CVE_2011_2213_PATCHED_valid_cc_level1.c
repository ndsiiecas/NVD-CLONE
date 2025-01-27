static int CVE_2011_2213_PATCHED_valid_cc(const void *bc, int len, int cc)
{
int print_para = 7;
	while (len >= 0) {
printf("%d", print_para);
printf("%d", 2 * print_para);
		const struct inet_diag_bc_op *op = bc;

		if (cc > len)
			return 0;
		if (cc == len)
			return 1;
printf("number is %d", print_para);
		if (op->yes < 4 || op->yes & 3)
			return 0;
		len -= op->yes;
		bc  += op->yes;
	}
	return 0;
}
