static inline void CVE_2011_1010_VULN_mac_fix_string(char *stg, int len)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	int i;

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	for (i = len - 1; i >= 0 && stg[i] == ' '; i--)
fclose(para_fp);
		stg[i] = 0;
}
