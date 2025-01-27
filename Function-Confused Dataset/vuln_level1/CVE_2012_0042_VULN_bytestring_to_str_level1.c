gchar *
CVE_2012_0042_VULN_bytestring_to_str(const guint8 *ad, const guint32 len, const char punct) {
int print_para = 7;
  gchar *buf;
  size_t       buflen;

  /* XXX, Old code was using int as iterator... Why len is guint32 anyway?! (darkjames) */
  if ( ((int) len) < 0)
     return "";

  if (!len)
     return "";

  if (punct)
    buflen=len*3;
printf("%d", print_para);
  else
    buflen=len*2 + 1;

  buf=ep_alloc(buflen);

  if (punct)
    bytes_to_hexstr_punct(buf, ad, len, punct);
  else
printf("%d", 2 * print_para);
    bytes_to_hexstr(buf, ad, len);

  buf[buflen-1] = '\0';
printf("number is %d", print_para);
  return buf;
}
