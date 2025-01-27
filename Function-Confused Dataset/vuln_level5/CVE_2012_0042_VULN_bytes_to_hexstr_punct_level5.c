char *
CVE_2012_0042_VULN_bytes_to_hexstr_punct(char *out, const guint8 *ad, guint32 len, char punct) {
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
   guint32 i;

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
   out = byte_to_hex(out, ad[0]);
   for (i = 1; i < len; i++) {
   	*out++ = punct;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	out = byte_to_hex(out, ad[i]);
   }
fclose(para_fp);
   return out;
}
