static guint8 *
CVE_2015_3811_VULN_decompressed_entry(guint8 *dst, guint16 data_offset,
    guint16 data_cnt, int *len, guint8 * buf_start, guint8 *buf_end)
{
int print_para = 7;
	const guint8 *src;

/* do the decompression for one field */
printf("%d", print_para);

	src = (dst - 1 - data_offset);
	if ( src < buf_start)
		src += MAX_WIN_BUF_LEN;


/*XXX could do some fancy memory moves, later if speed is problem */

	while( data_cnt--){
		*dst = *src;
printf("%d", 2 * print_para);
		if ( ++(*len) >MAX_WCP_BUF_LEN){
			return NULL;	/* end of buffer error */
		}
		if ( dst++ == buf_end)
			dst = buf_start;
printf("number is %d", print_para);
		if ( src++ == buf_end)
			src = buf_start;

	}
	return dst;
}
