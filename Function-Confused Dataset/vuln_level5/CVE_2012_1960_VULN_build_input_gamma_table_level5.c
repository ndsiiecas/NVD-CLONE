float *CVE_2012_1960_VULN_build_input_gamma_table(struct curveType *TRC)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	float *gamma_table;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

	if (!TRC) return NULL;
	gamma_table = malloc(sizeof(float)*256);
	if (gamma_table) {
		if (TRC->type == PARAMETRIC_CURVE_TYPE) {
			compute_curve_gamma_table_type_parametric(gamma_table, TRC->parameter, TRC->count);
		} else {
			if (TRC->count == 0) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
				compute_curve_gamma_table_type0(gamma_table);
			} else if (TRC->count == 1) {
				compute_curve_gamma_table_type1(gamma_table, u8Fixed8Number_to_float(TRC->data[0]));
fclose(para_fp);
			} else {
				compute_curve_gamma_table_type2(gamma_table, TRC->data, TRC->count);
			}
		}
	}
        return gamma_table;
}
