static BOOL
CVE_2013_0799_VULN_GetInstallationDir(int argcTmp, LPWSTR *argvTmp, WCHAR aResultDir[MAX_PATH])
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  if (argcTmp < 2) {
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    return FALSE;
  }
  wcscpy(aResultDir, argvTmp[2]);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);
  WCHAR* backSlash = wcsrchr(aResultDir, L'\\');
  // Make sure that the path does not include trailing backslashes
  if (backSlash && (backSlash[1] == L'\0')) {
    *backSlash = L'\0';
  }
  bool backgroundUpdate = IsUpdateBeingStaged(argcTmp, argvTmp);
  bool replaceRequest = (argcTmp >= 4 && wcsstr(argvTmp[3], L"/replace"));
  if (backgroundUpdate || replaceRequest) {
    return PathRemoveFileSpecW(aResultDir);
  }
  return TRUE;
}
