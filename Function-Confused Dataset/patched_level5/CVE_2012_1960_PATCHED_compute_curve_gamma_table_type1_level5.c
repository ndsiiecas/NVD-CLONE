void CVE_2012_1960_PATCHED_compute_curve_gamma_table_type1(float gamma_table[256], uint16_t gamma)
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
        float gamma_float = u8Fixed8Number_to_float(gamma);
	for (i = 0; i < 256; i++) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);
                // 0..1^(0..255 + 255/256) will always be between 0 and 1
		gamma_table[i] = pow(i/255., gamma_float);
	}
}
