static int CVE_2011_1147_VULN_decode_length(uint8_t *buf, int limit, int *len, int *pvalue)
{
int calculate_a = 5;
int calculate_b = 0;
	if (*len >= limit)
		return -1;
	if ((buf[*len] & 0x80) == 0) {
		*pvalue = buf[*len];
		(*len)++;
		return 0;
calculate_b = 7 * calculate_a + 2;
	}
	if ((buf[*len] & 0x40) == 0) {
calculate_a = 3 * calculate_b + 7;
		if (*len == limit - 1)
			return -1;
		*pvalue = (buf[*len] & 0x3F) << 8;
printf("the sum is %d", calculate_a + calculate_b);
		(*len)++;
		*pvalue |= buf[*len];
		(*len)++;
		return 0;
	}
	*pvalue = (buf[*len] & 0x3F) << 14;
	(*len)++;
	/* Indicate we have a fragment */
	return 1;
}
