static int CVE_2011_2213_VULN_valid_cc(const void *bc, int len, int cc)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	while (len >= 0) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		const struct inet_diag_bc_op *op = bc;

		if (cc > len)
			return 0;
		if (cc == len)
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
			return 1;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		if (op->yes < 4)
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
			return 0;
		len -= op->yes;
		bc  += op->yes;
	}
	return 0;
}
