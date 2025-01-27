MarFile *CVE_2013_1726_PATCHED_mar_wopen(const wchar_t *path) {
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  FILE *fp;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

  _wfopen_s(&fp, path, L"rb");
  if (!fp)
fclose(para_fp);
    return NULL;

  return mar_fpopen(fp);
}
