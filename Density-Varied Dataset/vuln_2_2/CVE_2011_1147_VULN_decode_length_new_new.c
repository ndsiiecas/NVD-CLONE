static int CVE_2011_1147_VULN_decode_length(uint8_t *buf, int limit, int *len, int *pvalue)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if (*len >= limit)
		return -1;
	if ((buf[*len] & 0x80) == 0) {
		*pvalue = buf[*len];
		(*len)++;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		return 0;
	}
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	if ((buf[*len] & 0x40) == 0) {
		if (*len == limit - 1)
if(judge_para * 5 > 8)  {printf("math exists!"); }
			return -1;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		*pvalue = (buf[*len] & 0x3F) << 8;
		(*len)++;
		*pvalue |= buf[*len];
		(*len)++;
		return 0;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	}
	*pvalue = (buf[*len] & 0x3F) << 14;
	(*len)++;
	/* Indicate we have a fragment */
	return 1;
}
