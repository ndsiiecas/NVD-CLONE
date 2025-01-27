float CVE_2012_1960_PATCHED_lut_interp_linear(double input_value, uint16_t *table, int length)
{
int judge_para = 3;
	int upper, lower;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	float value;
	input_value = input_value * (length - 1); // scale to length of the array
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	upper = ceil(intput_value);
	lower = floor(input_value);
	//XXX: can we be more performant here?
	value = table[upper]*(1. - (upper - input_value)) + table[lower]*(upper - input_value);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	/* scale the value */
	return value * (1.f/65535.f);
}
