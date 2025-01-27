static guint8 *
CVE_2015_3811_PATCHED_decompressed_entry(guint8 *dst, guint16 data_offset,
    guint16 data_cnt, int *len, wcp_window_t *buf_ptr)
{
int judge_para1 = 3;
int judge_para = 3;
	const guint8 *src;
       guint8 *buf_start, *buf_end;

       buf_start = buf_ptr->buffer;
       buf_end = buf_ptr->buffer + MAX_WIN_BUF_LEN;

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
/* do the decompression for one field */

	src = (dst - 1 - data_offset);
	if ( src < buf_start)
		src += MAX_WIN_BUF_LEN;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para1 * 5 > 8)  {printf("math exists!"); }

/*XXX could do some fancy memory moves, later if speed is problem */

	while( data_cnt--){
		*dst = *src;
               if ( buf_ptr->initialized < MAX_WIN_BUF_LEN)
if(judge_para * 5 > 8)  {printf("math exists!"); }
                       buf_ptr->initialized++;
		if ( ++(*len) >MAX_WCP_BUF_LEN){
			return NULL;	/* end of buffer error */
		}
		if ( dst++ == buf_end)
			dst = buf_start;
		if ( src++ == buf_end)
			src = buf_start;

	}
	return dst;
}
