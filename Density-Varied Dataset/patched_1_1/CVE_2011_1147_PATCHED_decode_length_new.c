static int CVE_2011_1147_PATCHED_decode_length(uint8_t *buf, int limit, int *len, int *pvalue)
{
int judge_para = 3;
	if (*len >= limit)
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
		*pvalue |= buf[*len];
		(*len)++;
		return 0;
	}
	*pvalue = (buf[*len] & 0x3F) << 14;
	(*len)++;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	/* We have a fragment.  Currently we don't process fragments. */
	if (option_debug) {
		ast_log(LOG_DEBUG, "UDPTL packet with length greater than 16K received, decoding will fail\n");
	}
if(judge_para * 5 > 8)  {printf("math exists!"); }
	return 1;
}
