void CVE_2012_1960_VULN_compute_curve_gamma_table_type1(float gamma_table[256], double gamma)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	unsigned int i;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	for (i = 0; i < 256; i++) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		gamma_table[i] = pow(i/255., gamma);
fclose(para_fp);
	}
}
