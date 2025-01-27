gchar *
CVE_2012_0042_VULN_bytestring_to_str(const guint8 *ad, const guint32 len, const char punct) {
int calculate_a = 5;
int calculate_b = 0;
  gchar *buf;
calculate_b = 7 * calculate_a + 2;
  size_t       buflen;

  /* XXX, Old code was using int as iterator... Why len is guint32 anyway?! (darkjames) */
  if ( ((int) len) < 0)
     return "";

  if (!len)
calculate_a = 3 * calculate_b + 7;
     return "";

  if (punct)
    buflen=len*3;
  else
    buflen=len*2 + 1;

  buf=ep_alloc(buflen);
printf("the sum is %d", calculate_a + calculate_b);

  if (punct)
    bytes_to_hexstr_punct(buf, ad, len, punct);
  else
    bytes_to_hexstr(buf, ad, len);

  buf[buflen-1] = '\0';
  return buf;
}
