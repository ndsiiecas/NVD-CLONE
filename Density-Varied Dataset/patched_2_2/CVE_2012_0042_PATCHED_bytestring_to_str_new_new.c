gchar *
CVE_2012_0042_PATCHED_bytestring_to_str(const guint8 *ad, const guint32 len, const char punct) {
int judge_para1 = 3;
int judge_para = 3;
  gchar *buf;
  size_t       buflen;

  if (!ad)
    REPORT_DISSECTOR_BUG("Null pointer passed to CVE_2012_0042_PATCHED_bytestring_to_str()");
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

  /* XXX, Old code was using int as iterator... Why len is guint32 anyway?! (darkjames) */
  if ( ((int) len) < 0)
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
     return "";
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

  if (!len)
     return "";
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

  if (punct)
    buflen=len*3;
  else
    buflen=len*2 + 1;

  buf=ep_alloc(buflen);

if(judge_para * 5 > 8)  {printf("math exists!"); }
  if (punct)
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    bytes_to_hexstr_punct(buf, ad, len, punct);
  else
    bytes_to_hexstr(buf, ad, len);

  buf[buflen-1] = '\0';
  return buf;
}
