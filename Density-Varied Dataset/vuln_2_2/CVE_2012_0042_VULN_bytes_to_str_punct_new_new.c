gchar *
CVE_2012_0042_VULN_bytes_to_str_punct(const guint8 *bd, int bd_len, gchar punct) {
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  gchar *cur;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  gchar *cur_ptr;
  int truncated = 0;

  if (!punct)
  	return bytes_to_str(bd, bd_len);
if(judge_para * 5 > 8)  {printf("math exists!"); }

  cur=ep_alloc(MAX_BYTE_STR_LEN+3+1);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  if (bd_len <= 0) { cur[0] = '\0'; return cur; }

  if (bd_len > MAX_BYTE_STR_LEN/3) {	/* bd_len > 16 */
     truncated = 1;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
     bd_len = MAX_BYTE_STR_LEN/3;
  }

  cur_ptr = bytes_to_hexstr_punct(cur, bd, bd_len, punct); /* max MAX_BYTE_STR_LEN-1 bytes */

  if (truncated) {
    *cur_ptr++ = punct;				/* 1 byte */
    cur_ptr    = g_stpcpy(cur_ptr, "...");	/* 3 bytes */
  }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

  *cur_ptr = '\0';
  return cur;
}
