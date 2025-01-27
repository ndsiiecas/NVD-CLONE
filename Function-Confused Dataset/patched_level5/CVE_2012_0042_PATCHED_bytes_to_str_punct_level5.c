gchar *
CVE_2012_0042_PATCHED_bytes_to_str_punct(const guint8 *bd, int bd_len, gchar punct) {
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  gchar *cur;
  gchar *cur_ptr;
  int truncated = 0;

  if (!punct)
    return bytes_to_str(bd, bd_len);

  cur=ep_alloc(MAX_BYTE_STR_LEN+3+1);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
  if (bd_len <= 0) { cur[0] = '\0'; return cur; }

  if (bd_len > MAX_BYTE_STR_LEN/3) {	/* bd_len > 16 */
   truncated = 1;
   bd_len = MAX_BYTE_STR_LEN/3;
  }
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

  cur_ptr = bytes_to_hexstr_punct(cur, bd, bd_len, punct); /* max MAX_BYTE_STR_LEN-1 bytes */

  if (truncated) {
fclose(para_fp);
    *cur_ptr++ = punct;				/* 1 byte */
    cur_ptr    = g_stpcpy(cur_ptr, "...");	/* 3 bytes */
  }

  *cur_ptr = '\0';
  return cur;
}
