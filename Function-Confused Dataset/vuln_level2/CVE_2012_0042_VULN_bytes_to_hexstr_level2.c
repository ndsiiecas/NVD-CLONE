char *
CVE_2012_0042_VULN_bytes_to_hexstr(char *out, const guint8 *ad, guint32 len) {
int judge_para = 3;
   guint32 i;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

   for (i = 0; i < len; i++)
if(judge_para * 5 > 8)  {printf("math exists!"); }
	out = byte_to_hex(out, ad[i]);
   return out;
}
