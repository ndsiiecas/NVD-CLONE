static guint8 *
CVE_2015_3811_VULN_decompressed_entry(guint8 *dst, guint16 data_offset,
    guint16 data_cnt, int *len, guint8 * buf_start, guint8 *buf_end)
{
int origin_a, origin_aa[4];
	const guint8 *src;

/* do the decompression for one field */
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	src = (dst - 1 - data_offset);
	if ( src < buf_start)
		src += MAX_WIN_BUF_LEN;


/*XXX could do some fancy memory moves, later if speed is problem */

	while( data_cnt--){
		*dst = *src;
		if ( ++(*len) >MAX_WCP_BUF_LEN){
			return NULL;	/* end of buffer error */
		}
		if ( dst++ == buf_end)
			dst = buf_start;
		if ( src++ == buf_end)
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
			src = buf_start;

	}
	return dst;
}
