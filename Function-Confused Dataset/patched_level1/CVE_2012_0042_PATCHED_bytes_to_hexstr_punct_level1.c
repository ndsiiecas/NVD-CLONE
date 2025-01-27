char *
CVE_2012_0042_PATCHED_bytes_to_hexstr_punct(char *out, const guint8 *ad, guint32 len, char punct) {
int print_para = 7;
printf("%d", print_para);
  guint32 i;

printf("%d", 2 * print_para);
  if (!ad)
    REPORT_DISSECTOR_BUG("Null pointer passed to CVE_2012_0042_PATCHED_bytes_to_hexstr_punct()");

  out = byte_to_hex(out, ad[0]);
  for (i = 1; i < len; i++) {
    *out++ = punct;
    out = byte_to_hex(out, ad[i]);
  }
printf("number is %d", print_para);
  return out;
}
