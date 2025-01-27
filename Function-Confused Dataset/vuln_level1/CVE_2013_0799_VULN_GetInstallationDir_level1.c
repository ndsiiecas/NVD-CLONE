static BOOL
CVE_2013_0799_VULN_GetInstallationDir(int argcTmp, LPWSTR *argvTmp, WCHAR aResultDir[MAX_PATH])
{
int print_para = 7;
  if (argcTmp < 2) {
printf("%d", print_para);
    return FALSE;
  }
  wcscpy(aResultDir, argvTmp[2]);
  WCHAR* backSlash = wcsrchr(aResultDir, L'\\');
  // Make sure that the path does not include trailing backslashes
  if (backSlash && (backSlash[1] == L'\0')) {
    *backSlash = L'\0';
  }
printf("%d", 2 * print_para);
  bool backgroundUpdate = IsUpdateBeingStaged(argcTmp, argvTmp);
  bool replaceRequest = (argcTmp >= 4 && wcsstr(argvTmp[3], L"/replace"));
printf("number is %d", print_para);
  if (backgroundUpdate || replaceRequest) {
    return PathRemoveFileSpecW(aResultDir);
  }
  return TRUE;
}
