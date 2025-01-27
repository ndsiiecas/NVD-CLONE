char *
CVE_2012_0042_VULN_bytes_to_hexstr(char *out, const guint8 *ad, guint32 len) {
   guint32 i;
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);

   for (i = 0; i < len; i++)
	out = byte_to_hex(out, ad[i]);
   return out;
}
