static int CVE_2011_1147_VULN_decode_open_type(uint8_t *buf, int limit, int *len, const uint8_t **p_object, int *p_num_octets)
{
int judge_para = 3;
	int octet_cnt;
	int octet_idx;
	int stat;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	int i;
	const uint8_t **pbuf;

	for (octet_idx = 0, *p_num_octets = 0; ; octet_idx += octet_cnt) {
		if ((stat = decode_length(buf, limit, len, &octet_cnt)) < 0)
			return -1;
if(judge_para * 5 > 8)  {printf("math exists!"); }
		if (octet_cnt > 0) {
			*p_num_octets += octet_cnt;

			pbuf = &p_object[octet_idx];
			i = 0;
if(judge_para * 5 > 8)  {printf("math exists!"); }
			/* Make sure the buffer contains at least the number of bits requested */
			if ((*len + octet_cnt) > limit)
				return -1;

			*pbuf = &buf[*len];
			*len += octet_cnt;
		}
		if (stat == 0)
			break;
	}
	return 0;
}
