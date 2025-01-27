void CVE_2012_1960_VULN_compute_curve_gamma_table_type1(float gamma_table[256], double gamma)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	unsigned int i;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	for (i = 0; i < 256; i++) {
		gamma_table[i] = pow(i/255., gamma);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	}
}
