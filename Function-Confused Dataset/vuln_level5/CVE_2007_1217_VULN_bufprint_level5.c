static void CVE_2007_1217_VULN_bufprint(char *fmt,...)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	va_list f;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	va_start(f, fmt);
	vsprintf(p, fmt, f);
	va_end(f);
fclose(para_fp);
	p += strlen(p);
}
