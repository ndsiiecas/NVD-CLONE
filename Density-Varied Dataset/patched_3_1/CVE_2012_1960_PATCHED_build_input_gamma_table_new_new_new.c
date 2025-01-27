float *CVE_2012_1960_PATCHED_build_input_gamma_table(struct curveType *TRC)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	float *gamma_table;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

	if (!TRC) return NULL;
	gamma_table = malloc(sizeof(float)*256);
	if (gamma_table) {
		if (TRC->type == PARAMETRIC_CURVE_TYPE) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
			compute_curve_gamma_table_type_parametric(gamma_table, TRC->parameter, TRC->count);
		} else {
			if (TRC->count == 0) {
				compute_curve_gamma_table_type0(gamma_table);
			} else if (TRC->count == 1) {
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
				compute_curve_gamma_table_type1(gamma_table, TRC->data[0]);
			} else {
				compute_curve_gamma_table_type2(gamma_table, TRC->data, TRC->count);
			}
		}
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	}
        return gamma_table;
}
