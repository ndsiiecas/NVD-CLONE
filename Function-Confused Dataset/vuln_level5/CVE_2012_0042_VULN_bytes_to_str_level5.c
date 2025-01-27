gchar *
CVE_2012_0042_VULN_bytes_to_str(const guint8 *bd, int bd_len) {
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  gchar *cur;
  gchar *cur_ptr;
  int truncated = 0;

  cur=ep_alloc(MAX_BYTE_STR_LEN+3+1);
  if (bd_len <= 0) { cur[0] = '\0'; return cur; }

  if (bd_len > MAX_BYTE_STR_LEN/2) {	/* bd_len > 24 */
    truncated = 1;
    bd_len = MAX_BYTE_STR_LEN/2;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
  }

  cur_ptr = bytes_to_hexstr(cur, bd, bd_len);	/* max MAX_BYTE_STR_LEN bytes */
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

  if (truncated)
fclose(para_fp);
    cur_ptr = g_stpcpy(cur_ptr, "...");		/* 3 bytes */

  *cur_ptr = '\0';				/* 1 byte */
  return cur;
}
