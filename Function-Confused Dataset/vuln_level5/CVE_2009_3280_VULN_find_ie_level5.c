static u8 *CVE_2009_3280_VULN_find_ie(u8 num, u8 *ies, size_t len)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	while (len > 2 && ies[0] != num) {
		len -= ies[1] + 2;
		ies += ies[1] + 2;
	}
	if (len < 2)
		return NULL;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	if (len < 2 + ies[1])
fclose(para_fp);
		return NULL;
	return ies;
}
