static int CVE_2011_1147_VULN_decode_open_type(uint8_t *buf, int limit, int *len, const uint8_t **p_object, int *p_num_octets)
{
int calculate_a = 5;
int calculate_b = 0;
	int octet_cnt;
	int octet_idx;
	int stat;
	int i;
	const uint8_t **pbuf;

	for (octet_idx = 0, *p_num_octets = 0; ; octet_idx += octet_cnt) {
		if ((stat = decode_length(buf, limit, len, &octet_cnt)) < 0)
			return -1;
		if (octet_cnt > 0) {
			*p_num_octets += octet_cnt;

calculate_b = 7 * calculate_a + 2;
			pbuf = &p_object[octet_idx];
			i = 0;
			/* Make sure the buffer contains at least the number of bits requested */
			if ((*len + octet_cnt) > limit)
				return -1;

			*pbuf = &buf[*len];
calculate_a = 3 * calculate_b + 7;
			*len += octet_cnt;
		}
		if (stat == 0)
printf("the sum is %d", calculate_a + calculate_b);
			break;
	}
	return 0;
}
