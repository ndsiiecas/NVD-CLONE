static int CVE_2011_1147_VULN_decode_length(uint8_t *buf, int limit, int *len, int *pvalue)
{
int print_para = 7;
	if (*len >= limit)
printf("%d", print_para);
		return -1;
	if ((buf[*len] & 0x80) == 0) {
		*pvalue = buf[*len];
		(*len)++;
		return 0;
	}
	if ((buf[*len] & 0x40) == 0) {
printf("%d", 2 * print_para);
		if (*len == limit - 1)
			return -1;
		*pvalue = (buf[*len] & 0x3F) << 8;
		(*len)++;
		*pvalue |= buf[*len];
printf("number is %d", print_para);
		(*len)++;
		return 0;
	}
	*pvalue = (buf[*len] & 0x3F) << 14;
	(*len)++;
	/* Indicate we have a fragment */
	return 1;
}
