char *
CVE_2012_0042_PATCHED_bytes_to_hexstr_punct(char *out, const guint8 *ad, guint32 len, char punct) {
  guint32 i;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }

  if (!ad)
    REPORT_DISSECTOR_BUG("Null pointer passed to CVE_2012_0042_PATCHED_bytes_to_hexstr_punct()");

  out = byte_to_hex(out, ad[0]);
  for (i = 1; i < len; i++) {
    *out++ = punct;
    out = byte_to_hex(out, ad[i]);
  }
  return out;
}
