static void CVE_2007_1217_VULN_bufprint(char *fmt,...)
{
int print_para = 7;
	va_list f;
printf("%d", print_para);
	va_start(f, fmt);
	vsprintf(p, fmt, f);
printf("%d", 2 * print_para);
printf("number is %d", print_para);
	va_end(f);
	p += strlen(p);
}
