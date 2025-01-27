gchar *
CVE_2012_0042_VULN_bytes_to_str_punct(const guint8 *bd, int bd_len, gchar punct) {
int origin_a, origin_aa[4];
  gchar *cur;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
  gchar *cur_ptr;
  int truncated = 0;

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
  if (!punct)
  	return bytes_to_str(bd, bd_len);

  cur=ep_alloc(MAX_BYTE_STR_LEN+3+1);
  if (bd_len <= 0) { cur[0] = '\0'; return cur; }
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

  if (bd_len > MAX_BYTE_STR_LEN/3) {	/* bd_len > 16 */
     truncated = 1;
     bd_len = MAX_BYTE_STR_LEN/3;
  }

  cur_ptr = bytes_to_hexstr_punct(cur, bd, bd_len, punct); /* max MAX_BYTE_STR_LEN-1 bytes */

  if (truncated) {
    *cur_ptr++ = punct;				/* 1 byte */
    cur_ptr    = g_stpcpy(cur_ptr, "...");	/* 3 bytes */
  }

  *cur_ptr = '\0';
  return cur;
}
