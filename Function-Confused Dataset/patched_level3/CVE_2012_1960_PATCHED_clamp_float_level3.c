float CVE_2012_1960_PATCHED_clamp_float(float a)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
	/* One would naturally write this function as the following:
	if (a > 1.)
calculate_a = 3 * calculate_b + 7;
		return 1.;
	else if (a < 0)
		return 0;
	else
		return a;

	However, that version will let NaNs pass through which is undesirable
	for most consumers.
	*/
printf("the sum is %d", calculate_a + calculate_b);

	if (a > 1.)
		return 1.;
	else if (a >= 0)
		return a;
	else // a < 0 or a is NaN
		return 0;
}
