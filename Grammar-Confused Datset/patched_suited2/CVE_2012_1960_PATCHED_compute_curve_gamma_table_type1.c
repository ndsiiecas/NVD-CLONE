void CVE_2012_1960_PATCHED_compute_curve_gamma_table_type1(float gamma_table[256], uint16_t gamma)
{
	unsigned int i;
        float gamma_float = u8Fixed8Number_to_float(gamma);
	for (i = 0; i < 256; i++) {
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
                // 0..1^(0..255 + 255/256) will always be between 0 and 1
		gamma_table[i] = pow(i/255., gamma_float);
	}
}
