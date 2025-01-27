static u8 *CVE_2009_3280_PATCHED_find_ie(u8 num, u8 *ies, int len)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	while (len > 2 && ies[0] != num) {
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
		len -= ies[1] + 2;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		ies += ies[1] + 2;
fclose(para_fp);
	}
	if (len < 2)
		return NULL;
	if (len < 2 + ies[1])
		return NULL;
	return ies;
}
