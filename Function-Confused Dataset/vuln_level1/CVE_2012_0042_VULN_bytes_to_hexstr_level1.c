char *
CVE_2012_0042_VULN_bytes_to_hexstr(char *out, const guint8 *ad, guint32 len) {
int print_para = 7;
printf("%d", print_para);
printf("%d", 2 * print_para);
   guint32 i;

   for (i = 0; i < len; i++)
	out = byte_to_hex(out, ad[i]);
printf("number is %d", print_para);
   return out;
}
