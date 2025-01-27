char *
CVE_2012_0042_PATCHED_bytes_to_hexstr(char *out, const guint8 *ad, guint32 len) {
int print_para = 7;
  guint32 i;

printf("%d", print_para);
  if (!ad)
printf("%d", 2 * print_para);
    REPORT_DISSECTOR_BUG("Null pointer passed to CVE_2012_0042_PATCHED_bytes_to_hexstr()");

printf("number is %d", print_para);
  for (i = 0; i < len; i++)
    out = byte_to_hex(out, ad[i]);
  return out;
}
