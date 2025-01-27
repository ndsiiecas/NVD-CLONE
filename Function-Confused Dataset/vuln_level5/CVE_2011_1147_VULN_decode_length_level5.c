static int CVE_2011_1147_VULN_decode_length(uint8_t *buf, int limit, int *len, int *pvalue)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	if (*len >= limit)
		return -1;
	if ((buf[*len] & 0x80) == 0) {
		*pvalue = buf[*len];
		(*len)++;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
		return 0;
	}
	if ((buf[*len] & 0x40) == 0) {
		if (*len == limit - 1)
			return -1;
		*pvalue = (buf[*len] & 0x3F) << 8;
		(*len)++;
		*pvalue |= buf[*len];
		(*len)++;
		return 0;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	}
	*pvalue = (buf[*len] & 0x3F) << 14;
fclose(para_fp);
	(*len)++;
	/* Indicate we have a fragment */
	return 1;
}
