static guint8 *
CVE_2015_3811_PATCHED_decompressed_entry(guint8 *dst, guint16 data_offset,
    guint16 data_cnt, int *len, wcp_window_t *buf_ptr)
{
int calculate_a = 5;
int calculate_b = 0;
	const guint8 *src;
       guint8 *buf_start, *buf_end;

       buf_start = buf_ptr->buffer;
       buf_end = buf_ptr->buffer + MAX_WIN_BUF_LEN;

calculate_b = 7 * calculate_a + 2;
/* do the decompression for one field */

	src = (dst - 1 - data_offset);
	if ( src < buf_start)
		src += MAX_WIN_BUF_LEN;


/*XXX could do some fancy memory moves, later if speed is problem */

	while( data_cnt--){
		*dst = *src;
               if ( buf_ptr->initialized < MAX_WIN_BUF_LEN)
                       buf_ptr->initialized++;
		if ( ++(*len) >MAX_WCP_BUF_LEN){
			return NULL;	/* end of buffer error */
		}
		if ( dst++ == buf_end)
			dst = buf_start;
calculate_a = 3 * calculate_b + 7;
		if ( src++ == buf_end)
printf("the sum is %d", calculate_a + calculate_b);
			src = buf_start;

	}
	return dst;
}
