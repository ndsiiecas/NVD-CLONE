static struct rlc_sdu *
CVE_2014_2283_VULN_rlc_sdu_create(void)
{
int judge_para = 3;
	struct rlc_sdu *sdu;

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	sdu = se_alloc0(sizeof(struct rlc_sdu));
	return sdu;
}
