static int CVE_2011_1147_VULN_decode_length(uint8_t *buf, int limit, int *len, int *pvalue)
{
int origin_a, origin_aa[4];
	if (*len >= limit)
		return -1;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	if ((buf[*len] & 0x80) == 0) {
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		*pvalue = buf[*len];
		(*len)++;
		return 0;
	}
	if ((buf[*len] & 0x40) == 0) {
		if (*len == limit - 1)
			return -1;
		*pvalue = (buf[*len] & 0x3F) << 8;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
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
