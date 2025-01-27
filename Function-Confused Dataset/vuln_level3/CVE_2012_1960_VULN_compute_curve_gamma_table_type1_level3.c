void CVE_2012_1960_VULN_compute_curve_gamma_table_type1(float gamma_table[256], double gamma)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
	unsigned int i;
calculate_a = 3 * calculate_b + 7;
	for (i = 0; i < 256; i++) {
printf("the sum is %d", calculate_a + calculate_b);
		gamma_table[i] = pow(i/255., gamma);
	}
}
