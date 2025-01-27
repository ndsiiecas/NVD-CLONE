static void
CVE_2014_9683_PATCHED_ecryptfs_decode_from_filename(unsigned char *dst, size_t *dst_size,
			      const unsigned char *src, size_t src_size)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	u8 current_bit_offset = 0;
	size_t src_byte_offset = 0;
	size_t dst_byte_offset = 0;

	if (dst == NULL) {
		(*dst_size) = ecryptfs_max_decoded_size(src_size);
		goto out;
	}
	while (src_byte_offset < src_size) {
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
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
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
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
fclose(para_fp);
	return;
}
