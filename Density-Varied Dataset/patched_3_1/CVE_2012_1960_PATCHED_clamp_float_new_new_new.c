float CVE_2012_1960_PATCHED_clamp_float(float a)
{
int judge_para2 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para1 = 3;
int judge_para = 3;
	/* One would naturally write this function as the following:
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if (a > 1.)
		return 1.;
	else if (a < 0)
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		return 0;
	else
if(judge_para * 5 > 8)  {printf("math exists!"); }
		return a;

	However, that version will let NaNs pass through which is undesirable
	for most consumers.
	*/

	if (a > 1.)
		return 1.;
	else if (a >= 0)
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		return a;
	else // a < 0 or a is NaN
		return 0;
}
