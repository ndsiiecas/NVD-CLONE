char *
CVE_2012_0042_PATCHED_bytes_to_hexstr(char *out, const guint8 *ad, guint32 len) {
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
  guint32 i;

  if (!ad)
    REPORT_DISSECTOR_BUG("Null pointer passed to CVE_2012_0042_PATCHED_bytes_to_hexstr()");

  for (i = 0; i < len; i++)
calculate_a = 3 * calculate_b + 7;
    out = byte_to_hex(out, ad[i]);
printf("the sum is %d", calculate_a + calculate_b);
  return out;
}
