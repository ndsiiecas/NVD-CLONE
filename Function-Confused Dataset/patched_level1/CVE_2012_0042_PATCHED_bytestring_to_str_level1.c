gchar *
CVE_2012_0042_PATCHED_bytestring_to_str(const guint8 *ad, const guint32 len, const char punct) {
int print_para = 7;
printf("%d", print_para);
  gchar *buf;
printf("%d", 2 * print_para);
  size_t       buflen;

  if (!ad)
    REPORT_DISSECTOR_BUG("Null pointer passed to CVE_2012_0042_PATCHED_bytestring_to_str()");

  /* XXX, Old code was using int as iterator... Why len is guint32 anyway?! (darkjames) */
  if ( ((int) len) < 0)
     return "";

  if (!len)
     return "";

  if (punct)
    buflen=len*3;
  else
    buflen=len*2 + 1;

  buf=ep_alloc(buflen);

  if (punct)
    bytes_to_hexstr_punct(buf, ad, len, punct);
  else
    bytes_to_hexstr(buf, ad, len);
printf("number is %d", print_para);

  buf[buflen-1] = '\0';
  return buf;
}
