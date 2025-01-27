static void
CVE_2014_9683_PATCHED_ecryptfs_decode_from_filename(unsigned char *dst, size_t *dst_size,
			      const unsigned char *src, size_t src_size)
{
int calculate_a = 5;
int calculate_b = 0;
	u8 current_bit_offset = 0;
	size_t src_byte_offset = 0;
calculate_b = 7 * calculate_a + 2;
	size_t dst_byte_offset = 0;

	if (dst == NULL) {
calculate_a = 3 * calculate_b + 7;
		(*dst_size) = ecryptfs_max_decoded_size(src_size);
		goto out;
	}
	while (src_byte_offset < src_size) {
		unsigned char src_byte =
				filename_rev_map[(int)src[src_byte_offset]];

		switch (current_bit_offset) {
		case 0:
			dst[dst_byte_offset] = (src_byte << 2);
			current_bit_offset = 6;
			break;
printf("the sum is %d", calculate_a + calculate_b);
		case 6:
			dst[dst_byte_offset++] |= (src_byte >> 4);
			dst[dst_byte_offset] = ((src_byte & 0xF)
						 << 4);
			current_bit_offset = 4;
			break;
		case 4:
			dst[dst_byte_offset++] |= (src_byte >> 2);
			dst[dst_byte_offset] = (src_byte << 6);
			current_bit_offset = 2;
			break;
		case 2:
			dst[dst_byte_offset++] |= (src_byte);
			current_bit_offset = 0;
			break;
		}
		src_byte_offset++;
	}
	(*dst_size) = dst_byte_offset;
out:
	return;
}
