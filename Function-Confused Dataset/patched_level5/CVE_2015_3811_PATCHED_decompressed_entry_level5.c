static guint8 *
CVE_2015_3811_PATCHED_decompressed_entry(guint8 *dst, guint16 data_offset,
    guint16 data_cnt, int *len, wcp_window_t *buf_ptr)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	const guint8 *src;
       guint8 *buf_start, *buf_end;

       buf_start = buf_ptr->buffer;
       buf_end = buf_ptr->buffer + MAX_WIN_BUF_LEN;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

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
		if ( src++ == buf_end)
			src = buf_start;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);

	}
	return dst;
}
