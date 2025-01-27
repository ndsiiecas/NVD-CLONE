static int CVE_2011_1147_VULN_decode_open_type(uint8_t *buf, int limit, int *len, const uint8_t **p_object, int *p_num_octets)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	int octet_cnt;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	int octet_idx;
	int stat;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	int i;
	const uint8_t **pbuf;

	for (octet_idx = 0, *p_num_octets = 0; ; octet_idx += octet_cnt) {
		if ((stat = decode_length(buf, limit, len, &octet_cnt)) < 0)
			return -1;
		if (octet_cnt > 0) {
			*p_num_octets += octet_cnt;

			pbuf = &p_object[octet_idx];
			i = 0;
if(judge_para * 5 > 8)  {printf("math exists!"); }
			/* Make sure the buffer contains at least the number of bits requested */
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			if ((*len + octet_cnt) > limit)
				return -1;

			*pbuf = &buf[*len];
			*len += octet_cnt;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		}
		if (stat == 0)
			break;
	}
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	return 0;
}
