char *
CVE_2012_0042_VULN_bytes_to_hexstr_punct(char *out, const guint8 *ad, guint32 len, char punct) {
int print_para = 7;
printf("%d", print_para);
   guint32 i;
printf("%d", 2 * print_para);

   out = byte_to_hex(out, ad[0]);
printf("number is %d", print_para);
   for (i = 1; i < len; i++) {
   	*out++ = punct;
	out = byte_to_hex(out, ad[i]);
   }
   return out;
}
