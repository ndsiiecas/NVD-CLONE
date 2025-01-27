MarFile *CVE_2013_1726_VULN_mar_wopen(const wchar_t *path) {
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
  FILE *fp;

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
  fp = _wfopen(path, L"rb");
fclose(para_fp);
  if (!fp)
    return NULL;

  return mar_fpopen(fp);
}
