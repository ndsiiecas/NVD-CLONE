float CVE_2012_1960_VULN_clamp_float(float a)
{
int judge_para = 3;
        if (a > 1.)
                return 1.;
        else if (a < 0)
                return 0;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
        else
if(judge_para * 5 > 8)  {printf("math exists!"); }
                return a;
}
