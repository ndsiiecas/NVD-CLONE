static int CVE_2011_1147_PATCHED_decode_length(uint8_t *buf, int limit, int *len, int *pvalue)
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
		if (*len == limit - 1)
			return -1;
		*pvalue = (buf[*len] & 0x3F) << 8;
printf("%d", 2 * print_para);
		(*len)++;
		*pvalue |= buf[*len];
		(*len)++;
		return 0;
	}
	*pvalue = (buf[*len] & 0x3F) << 14;
	(*len)++;
	/* We have a fragment.  Currently we don't process fragments. */
	if (option_debug) {
printf("number is %d", print_para);
		ast_log(LOG_DEBUG, "UDPTL packet with length greater than 16K received, decoding will fail\n");
	}
	return 1;
}
