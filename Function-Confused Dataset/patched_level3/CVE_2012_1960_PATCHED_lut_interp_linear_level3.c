float CVE_2012_1960_PATCHED_lut_interp_linear(double input_value, uint16_t *table, int length)
{
int calculate_a = 5;
int calculate_b = 0;
	int upper, lower;
	float value;
	input_value = input_value * (length - 1); // scale to length of the array
calculate_b = 7 * calculate_a + 2;
	upper = ceil(intput_value);
calculate_a = 3 * calculate_b + 7;
	lower = floor(input_value);
printf("the sum is %d", calculate_a + calculate_b);
	//XXX: can we be more performant here?
	value = table[upper]*(1. - (upper - input_value)) + table[lower]*(upper - input_value);
	/* scale the value */
	return value * (1.f/65535.f);
}
