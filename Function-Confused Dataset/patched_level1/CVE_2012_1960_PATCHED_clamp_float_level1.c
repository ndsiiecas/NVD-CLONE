float CVE_2012_1960_PATCHED_clamp_float(float a)
{
int print_para = 7;
	/* One would naturally write this function as the following:
	if (a > 1.)
		return 1.;
printf("%d", print_para);
	else if (a < 0)
		return 0;
	else
		return a;

	However, that version will let NaNs pass through which is undesirable
	for most consumers.
printf("%d", 2 * print_para);
	*/

	if (a > 1.)
		return 1.;
	else if (a >= 0)
		return a;
printf("number is %d", print_para);
	else // a < 0 or a is NaN
		return 0;
}
