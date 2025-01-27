static int CVE_2011_1147_VULN_decode_open_type(uint8_t *buf, int limit, int *len, const uint8_t **p_object, int *p_num_octets)
{
int origin_a, origin_aa[4];
	int octet_cnt;
	int octet_idx;
	int stat;
	int i;
	const uint8_t **pbuf;

	for (octet_idx = 0, *p_num_octets = 0; ; octet_idx += octet_cnt) {
		if ((stat = decode_length(buf, limit, len, &octet_cnt)) < 0)
			return -1;
		if (octet_cnt > 0) {
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
			*p_num_octets += octet_cnt;

			pbuf = &p_object[octet_idx];
			i = 0;
			/* Make sure the buffer contains at least the number of bits requested */
			if ((*len + octet_cnt) > limit)
				return -1;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

			*pbuf = &buf[*len];
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
			*len += octet_cnt;
		}
		if (stat == 0)
			break;
	}
	return 0;
}
