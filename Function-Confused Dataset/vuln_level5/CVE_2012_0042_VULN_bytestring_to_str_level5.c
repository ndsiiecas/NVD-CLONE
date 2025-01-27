gchar *
CVE_2012_0042_VULN_bytestring_to_str(const guint8 *ad, const guint32 len, const char punct) {
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  gchar *buf;
  size_t       buflen;

  /* XXX, Old code was using int as iterator... Why len is guint32 anyway?! (darkjames) */
  if ( ((int) len) < 0)
     return "";

  if (!len)
     return "";

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
  if (punct)
    buflen=len*3;
  else
    buflen=len*2 + 1;

  buf=ep_alloc(buflen);

  if (punct)
    bytes_to_hexstr_punct(buf, ad, len, punct);
  else
    bytes_to_hexstr(buf, ad, len);

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);
  buf[buflen-1] = '\0';
  return buf;
}
