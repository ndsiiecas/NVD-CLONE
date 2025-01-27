static int CVE_2011_1147_PATCHED_decode_open_type(uint8_t *buf, int limit, int *len, const uint8_t **p_object, int *p_num_octets)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	int octet_cnt = 0;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	if (decode_length(buf, limit, len, &octet_cnt) != 0)
		return -1;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if (octet_cnt > 0) {
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		/* Make sure the buffer contains at least the number of bits requested */
		if ((*len + octet_cnt) > limit)
			return -1;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		*p_num_octets = octet_cnt;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		*p_object = &buf[*len];
		*len += octet_cnt;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	}

	return 0;
}
