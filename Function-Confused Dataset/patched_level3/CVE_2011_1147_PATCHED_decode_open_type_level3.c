static int CVE_2011_1147_PATCHED_decode_open_type(uint8_t *buf, int limit, int *len, const uint8_t **p_object, int *p_num_octets)
{
int calculate_a = 5;
int calculate_b = 0;
	int octet_cnt = 0;

	if (decode_length(buf, limit, len, &octet_cnt) != 0)
		return -1;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;

	if (octet_cnt > 0) {
		/* Make sure the buffer contains at least the number of bits requested */
		if ((*len + octet_cnt) > limit)
			return -1;

		*p_num_octets = octet_cnt;
		*p_object = &buf[*len];
		*len += octet_cnt;
	}
printf("the sum is %d", calculate_a + calculate_b);

	return 0;
}
