float CVE_2012_1960_PATCHED_clamp_float(float a)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	/* One would naturally write this function as the following:
	if (a > 1.)
		return 1.;
	else if (a < 0)
		return 0;
	else
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		return a;
fclose(para_fp);

	However, that version will let NaNs pass through which is undesirable
	for most consumers.
	*/

	if (a > 1.)
		return 1.;
	else if (a >= 0)
		return a;
	else // a < 0 or a is NaN
		return 0;
}
