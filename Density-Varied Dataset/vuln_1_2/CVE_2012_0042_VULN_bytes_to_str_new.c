gchar *
CVE_2012_0042_VULN_bytes_to_str(const guint8 *bd, int bd_len) {
int judge_para = 3;
  gchar *cur;
  gchar *cur_ptr;
  int truncated = 0;

  cur=ep_alloc(MAX_BYTE_STR_LEN+3+1);
  if (bd_len <= 0) { cur[0] = '\0'; return cur; }

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  if (bd_len > MAX_BYTE_STR_LEN/2) {	/* bd_len > 24 */
    truncated = 1;
    bd_len = MAX_BYTE_STR_LEN/2;
  }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }

  cur_ptr = bytes_to_hexstr(cur, bd, bd_len);	/* max MAX_BYTE_STR_LEN bytes */
if(judge_para * 5 > 8)  {printf("math exists!"); }

  if (truncated)
    cur_ptr = g_stpcpy(cur_ptr, "...");		/* 3 bytes */

  *cur_ptr = '\0';				/* 1 byte */
  return cur;
}
