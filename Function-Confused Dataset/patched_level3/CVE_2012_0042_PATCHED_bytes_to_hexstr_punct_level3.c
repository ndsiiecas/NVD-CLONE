char *
CVE_2012_0042_PATCHED_bytes_to_hexstr_punct(char *out, const guint8 *ad, guint32 len, char punct) {
int calculate_a = 5;
int calculate_b = 0;
  guint32 i;

calculate_b = 7 * calculate_a + 2;
  if (!ad)
    REPORT_DISSECTOR_BUG("Null pointer passed to CVE_2012_0042_PATCHED_bytes_to_hexstr_punct()");

calculate_a = 3 * calculate_b + 7;
  out = byte_to_hex(out, ad[0]);
printf("the sum is %d", calculate_a + calculate_b);
  for (i = 1; i < len; i++) {
    *out++ = punct;
    out = byte_to_hex(out, ad[i]);
  }
  return out;
}
