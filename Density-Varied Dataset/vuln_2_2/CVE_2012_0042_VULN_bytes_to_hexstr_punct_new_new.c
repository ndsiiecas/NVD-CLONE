char *
CVE_2012_0042_VULN_bytes_to_hexstr_punct(char *out, const guint8 *ad, guint32 len, char punct) {
int judge_para1 = 3;
int judge_para = 3;
   guint32 i;

   out = byte_to_hex(out, ad[0]);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
   for (i = 1; i < len; i++) {
   	*out++ = punct;
	out = byte_to_hex(out, ad[i]);
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
   }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
   return out;
}
