char *
CVE_2012_0042_PATCHED_bytes_to_hexstr(char *out, const guint8 *ad, guint32 len) {
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  guint32 i;

  if (!ad)
    REPORT_DISSECTOR_BUG("Null pointer passed to CVE_2012_0042_PATCHED_bytes_to_hexstr()");

  for (i = 0; i < len; i++)
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    out = byte_to_hex(out, ad[i]);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);
  return out;
}
