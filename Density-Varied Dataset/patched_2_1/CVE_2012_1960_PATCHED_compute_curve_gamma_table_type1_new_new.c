void CVE_2012_1960_PATCHED_compute_curve_gamma_table_type1(float gamma_table[256], uint16_t gamma)
{
int judge_para1 = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
	unsigned int i;
        float gamma_float = u8Fixed8Number_to_float(gamma);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	for (i = 0; i < 256; i++) {
                // 0..1^(0..255 + 255/256) will always be between 0 and 1
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		gamma_table[i] = pow(i/255., gamma_float);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	}
}
