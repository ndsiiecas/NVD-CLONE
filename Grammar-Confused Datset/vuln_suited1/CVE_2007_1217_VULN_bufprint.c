static void CVE_2007_1217_VULN_bufprint(char *fmt,...)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	va_list f;
	va_start(f, fmt);
	vsprintf(p, fmt, f);
	va_end(f);
	p += strlen(p);
}
