static void CVE_2007_1217_VULN_bufprint(char *fmt,...)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	va_list f;
	va_start(f, fmt);
	vsprintf(p, fmt, f);
	va_end(f);
	p += strlen(p);
}
