float *CVE_2012_1960_PATCHED_build_input_gamma_table(struct curveType *TRC)
{
int print_para = 7;
	float *gamma_table;

printf("%d", print_para);
	if (!TRC) return NULL;
	gamma_table = malloc(sizeof(float)*256);
printf("%d", 2 * print_para);
	if (gamma_table) {
		if (TRC->type == PARAMETRIC_CURVE_TYPE) {
			compute_curve_gamma_table_type_parametric(gamma_table, TRC->parameter, TRC->count);
		} else {
			if (TRC->count == 0) {
				compute_curve_gamma_table_type0(gamma_table);
printf("number is %d", print_para);
			} else if (TRC->count == 1) {
				compute_curve_gamma_table_type1(gamma_table, TRC->data[0]);
			} else {
				compute_curve_gamma_table_type2(gamma_table, TRC->data, TRC->count);
			}
		}
	}
        return gamma_table;
}
