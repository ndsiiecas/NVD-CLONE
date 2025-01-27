char *
CVE_2012_0042_VULN_bytes_to_hexstr_punct(char *out, const guint8 *ad, guint32 len, char punct) {
int calculate_a = 5;
int calculate_b = 0;
   guint32 i;

calculate_b = 7 * calculate_a + 2;
   out = byte_to_hex(out, ad[0]);
   for (i = 1; i < len; i++) {
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
   	*out++ = punct;
	out = byte_to_hex(out, ad[i]);
   }
   return out;
}
