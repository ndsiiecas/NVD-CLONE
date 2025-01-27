static void
CVE_2014_9683_PATCHED_ecryptfs_decode_from_filename(unsigned char *dst, size_t *dst_size,
			      const unsigned char *src, size_t src_size)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	u8 current_bit_offset = 0;
	size_t src_byte_offset = 0;
	size_t dst_byte_offset = 0;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

	if (dst == NULL) {
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		(*dst_size) = ecryptfs_max_decoded_size(src_size);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		goto out;
	}
	while (src_byte_offset < src_size) {
		unsigned char src_byte =
				filename_rev_map[(int)src[src_byte_offset]];

		switch (current_bit_offset) {
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		case 0:
			dst[dst_byte_offset] = (src_byte << 2);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
			current_bit_offset = 6;
			break;
		case 6:
			dst[dst_byte_offset++] |= (src_byte >> 4);
			dst[dst_byte_offset] = ((src_byte & 0xF)
						 << 4);
			current_bit_offset = 4;
			break;
		case 4:
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
			dst[dst_byte_offset++] |= (src_byte >> 2);
			dst[dst_byte_offset] = (src_byte << 6);
			current_bit_offset = 2;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
			break;
		case 2:
			dst[dst_byte_offset++] |= (src_byte);
			current_bit_offset = 0;
			break;
		}
		src_byte_offset++;
	}
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	(*dst_size) = dst_byte_offset;
out:
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	return;
}
