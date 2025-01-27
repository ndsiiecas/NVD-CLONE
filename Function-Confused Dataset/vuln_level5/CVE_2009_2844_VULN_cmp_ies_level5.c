static int CVE_2009_2844_VULN_cmp_ies(u8 num, u8 *ies1, size_t len1, u8 *ies2, size_t len2)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	const u8 *ie1 = find_ie(num, ies1, len1);
	const u8 *ie2 = find_ie(num, ies2, len2);
	int r;

	if (!ie1 && !ie2)
		return 0;
	if (!ie1)
		return -1;

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	r = memcmp(ie1 + 2, ie2 + 2, min(ie1[1], ie2[1]));
fclose(para_fp);
	if (r == 0 && ie1[1] != ie2[1])
		return ie2[1] - ie1[1];
	return r;
}
