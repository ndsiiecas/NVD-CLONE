float CVE_2012_1960_VULN_lut_interp_linear(double value, uint16_t *table, int length)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	int upper, lower;
	value = value * (length - 1); // scale to length of the array
	upper = ceil(value);
	lower = floor(value);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	//XXX: can we be more performant here?
	value = table[upper]*(1. - (upper - value)) + table[lower]*(upper - value);
	/* scale the value */
fclose(para_fp);
	return value * (1./65535.);
}
