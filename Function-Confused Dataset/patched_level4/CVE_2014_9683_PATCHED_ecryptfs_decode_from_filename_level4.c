static void
CVE_2014_9683_PATCHED_ecryptfs_decode_from_filename(unsigned char *dst, size_t *dst_size,
			      const unsigned char *src, size_t src_size)
{
int origin_a, origin_aa[4];
	u8 current_bit_offset = 0;
	size_t src_byte_offset = 0;
	size_t dst_byte_offset = 0;

	if (dst == NULL) {
		(*dst_size) = ecryptfs_max_decoded_size(src_size);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
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
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
			current_bit_offset = 0;
			break;
		}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		src_byte_offset++;
	}
	(*dst_size) = dst_byte_offset;
out:
	return;
}
