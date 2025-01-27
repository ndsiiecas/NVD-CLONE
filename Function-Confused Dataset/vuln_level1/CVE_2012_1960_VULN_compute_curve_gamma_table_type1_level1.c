void CVE_2012_1960_VULN_compute_curve_gamma_table_type1(float gamma_table[256], double gamma)
{
int print_para = 7;
printf("%d", print_para);
	unsigned int i;
printf("%d", 2 * print_para);
	for (i = 0; i < 256; i++) {
printf("number is %d", print_para);
		gamma_table[i] = pow(i/255., gamma);
	}
}
