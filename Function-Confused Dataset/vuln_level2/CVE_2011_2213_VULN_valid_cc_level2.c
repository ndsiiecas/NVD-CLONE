static int CVE_2011_2213_VULN_valid_cc(const void *bc, int len, int cc)
{
int judge_para = 3;
	while (len >= 0) {
		const struct inet_diag_bc_op *op = bc;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

		if (cc > len)
			return 0;
if(judge_para * 5 > 8)  {printf("math exists!"); }
		if (cc == len)
			return 1;
		if (op->yes < 4)
			return 0;
		len -= op->yes;
		bc  += op->yes;
	}
	return 0;
}
