float *CVE_2012_1960_PATCHED_build_input_gamma_table(struct curveType *TRC)
{
int calculate_a = 5;
int calculate_b = 0;
	float *gamma_table;

	if (!TRC) return NULL;
	gamma_table = malloc(sizeof(float)*256);
	if (gamma_table) {
calculate_b = 7 * calculate_a + 2;
		if (TRC->type == PARAMETRIC_CURVE_TYPE) {
			compute_curve_gamma_table_type_parametric(gamma_table, TRC->parameter, TRC->count);
calculate_a = 3 * calculate_b + 7;
		} else {
			if (TRC->count == 0) {
				compute_curve_gamma_table_type0(gamma_table);
			} else if (TRC->count == 1) {
				compute_curve_gamma_table_type1(gamma_table, TRC->data[0]);
			} else {
printf("the sum is %d", calculate_a + calculate_b);
				compute_curve_gamma_table_type2(gamma_table, TRC->data, TRC->count);
			}
		}
	}
        return gamma_table;
}
