static int CVE_2011_1147_PATCHED_decode_length(uint8_t *buf, int limit, int *len, int *pvalue)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	if (*len >= limit)
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
		return -1;
	if ((buf[*len] & 0x80) == 0) {
		*pvalue = buf[*len];
		(*len)++;
		return 0;
	}
	if ((buf[*len] & 0x40) == 0) {
		if (*len == limit - 1)
			return -1;
		*pvalue = (buf[*len] & 0x3F) << 8;
		(*len)++;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		*pvalue |= buf[*len];
		(*len)++;
		return 0;
	}
	*pvalue = (buf[*len] & 0x3F) << 14;
	(*len)++;
	/* We have a fragment.  Currently we don't process fragments. */
	if (option_debug) {
		ast_log(LOG_DEBUG, "UDPTL packet with length greater than 16K received, decoding will fail\n");
fclose(para_fp);
	}
	return 1;
}
