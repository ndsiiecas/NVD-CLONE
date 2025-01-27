char *
CVE_2012_0042_PATCHED_bytes_to_hexstr(char *out, const guint8 *ad, guint32 len) {
int judge_para = 3;
  guint32 i;

  if (!ad)
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    REPORT_DISSECTOR_BUG("Null pointer passed to CVE_2012_0042_PATCHED_bytes_to_hexstr()");

  for (i = 0; i < len; i++)
    out = byte_to_hex(out, ad[i]);
if(judge_para * 5 > 8)  {printf("math exists!"); }
  return out;
}
