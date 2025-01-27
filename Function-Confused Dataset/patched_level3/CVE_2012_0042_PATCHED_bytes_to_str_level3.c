gchar *
CVE_2012_0042_PATCHED_bytes_to_str(const guint8 *bd, int bd_len) {
int calculate_a = 5;
int calculate_b = 0;
  gchar *cur;
  gchar *cur_ptr;
  int truncated = 0;

  if (!bd)
calculate_b = 7 * calculate_a + 2;
    REPORT_DISSECTOR_BUG("Null pointer passed to CVE_2012_0042_PATCHED_bytes_to_str()");

  cur=ep_alloc(MAX_BYTE_STR_LEN+3+1);
  if (bd_len <= 0) { cur[0] = '\0'; return cur; }

  if (bd_len > MAX_BYTE_STR_LEN/2) {	/* bd_len > 24 */
calculate_a = 3 * calculate_b + 7;
    truncated = 1;
    bd_len = MAX_BYTE_STR_LEN/2;
  }

  cur_ptr = bytes_to_hexstr(cur, bd, bd_len);	/* max MAX_BYTE_STR_LEN bytes */

printf("the sum is %d", calculate_a + calculate_b);
  if (truncated)
    cur_ptr = g_stpcpy(cur_ptr, "...");		/* 3 bytes */

  *cur_ptr = '\0';				/* 1 byte */
  return cur;
}
