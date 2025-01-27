  CVE_2013_0797_VULN_AutoLoadSystemDependencies()
  {
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    static LPCWSTR delayDLLs[] = { L"wsock32.dll", L"crypt32.dll" };
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    WCHAR systemDirectory[MAX_PATH + 1] = { L'\0' };
    // If GetSystemDirectory fails we accept that we'll load the DLLs from the
    // normal search path.
    GetSystemDirectory(systemDirectory, MAX_PATH + 1);
    size_t systemDirLen = wcslen(systemDirectory);

    // Make the system directory path terminate with a slash
    if (systemDirectory[systemDirLen - 1] != L'\\' && systemDirLen) {
      systemDirectory[systemDirLen] = L'\\';
      ++systemDirLen;
      // No need to re-NULL terminate
    }

    // For each known DLL ensure it is loaded from the system32 directory
    for (size_t i = 0; i < sizeof(delayDLLs) / sizeof(delayDLLs[0]); ++i) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
      size_t fileLen = wcslen(delayDLLs[i]);
      wcsncpy(systemDirectory + systemDirLen, delayDLLs[i], 
              MAX_PATH - systemDirLen);
      if (systemDirLen + fileLen <= MAX_PATH) {
        systemDirectory[systemDirLen + fileLen] = L'\0';
      } else {
        systemDirectory[MAX_PATH] = L'\0';
fclose(para_fp);
      }
      LPCWSTR fullModulePath = systemDirectory; // just for code readability
      LoadLibraryW(fullModulePath);
    }
  }
