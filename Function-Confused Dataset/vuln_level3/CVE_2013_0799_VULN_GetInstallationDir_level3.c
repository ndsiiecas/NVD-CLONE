static BOOL
CVE_2013_0799_VULN_GetInstallationDir(int argcTmp, LPWSTR *argvTmp, WCHAR aResultDir[MAX_PATH])
{
int calculate_a = 5;
int calculate_b = 0;
  if (argcTmp < 2) {
    return FALSE;
  }
  wcscpy(aResultDir, argvTmp[2]);
  WCHAR* backSlash = wcsrchr(aResultDir, L'\\');
  // Make sure that the path does not include trailing backslashes
calculate_b = 7 * calculate_a + 2;
  if (backSlash && (backSlash[1] == L'\0')) {
    *backSlash = L'\0';
  }
calculate_a = 3 * calculate_b + 7;
  bool backgroundUpdate = IsUpdateBeingStaged(argcTmp, argvTmp);
printf("the sum is %d", calculate_a + calculate_b);
  bool replaceRequest = (argcTmp >= 4 && wcsstr(argvTmp[3], L"/replace"));
  if (backgroundUpdate || replaceRequest) {
    return PathRemoveFileSpecW(aResultDir);
  }
  return TRUE;
}
