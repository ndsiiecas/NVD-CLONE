static int CVE_2011_1147_PATCHED_decode_length(uint8_t *buf, int limit, int *len, int *pvalue)
{
int calculate_a = 5;
int calculate_b = 0;
	if (*len >= limit)
calculate_b = 7 * calculate_a + 2;
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
calculate_a = 3 * calculate_b + 7;
		(*len)++;
		*pvalue |= buf[*len];
		(*len)++;
		return 0;
	}
printf("the sum is %d", calculate_a + calculate_b);
	*pvalue = (buf[*len] & 0x3F) << 14;
	(*len)++;
	/* We have a fragment.  Currently we don't process fragments. */
	if (option_debug) {
		ast_log(LOG_DEBUG, "UDPTL packet with length greater than 16K received, decoding will fail\n");
	}
	return 1;
}
