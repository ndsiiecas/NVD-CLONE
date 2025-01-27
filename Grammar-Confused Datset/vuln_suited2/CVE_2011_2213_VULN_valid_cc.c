static int CVE_2011_2213_VULN_valid_cc(const void *bc, int len, int cc)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	while (len >= 0) {
		const struct inet_diag_bc_op *op = bc;

		if (cc > len)
			return 0;
		if (cc == len)
			return 1;
		if (op->yes < 4)
			return 0;
		len -= op->yes;
		bc  += op->yes;
	}
	return 0;
}
