static int CVE_2011_1147_PATCHED_decode_open_type(uint8_t *buf, int limit, int *len, const uint8_t **p_object, int *p_num_octets)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	int octet_cnt = 0;

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	if (decode_length(buf, limit, len, &octet_cnt) != 0)
		return -1;

	if (octet_cnt > 0) {
		/* Make sure the buffer contains at least the number of bits requested */
		if ((*len + octet_cnt) > limit)
			return -1;
fclose(para_fp);

		*p_num_octets = octet_cnt;
		*p_object = &buf[*len];
		*len += octet_cnt;
	}

	return 0;
}
