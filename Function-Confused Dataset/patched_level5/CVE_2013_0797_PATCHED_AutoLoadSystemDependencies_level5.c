  CVE_2013_0797_PATCHED_AutoLoadSystemDependencies()
  {
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    static LPCWSTR delayDLLs[] = { L"wsock32.dll", L"crypt32.dll",
                                   L"cryptsp.dll", L"cryptbase.dll",
                                   L"msasn1.dll", L"userenv.dll",
                                   L"secur32.dll" };

    WCHAR systemDirectory[MAX_PATH + 1] = { L'\0' };
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    // If GetSystemDirectory fails we accept that we'll load the DLLs from the
    // normal search path.
    GetSystemDirectory(systemDirectory, MAX_PATH + 1);
    size_t systemDirLen = wcslen(systemDirectory);

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    // Make the system directory path terminate with a slash
    if (systemDirectory[systemDirLen - 1] != L'\\' && systemDirLen) {
      systemDirectory[systemDirLen] = L'\\';
      ++systemDirLen;
      // No need to re-NULL terminate
    }

    // For each known DLL ensure it is loaded from the system32 directory
    for (size_t i = 0; i < sizeof(delayDLLs) / sizeof(delayDLLs[0]); ++i) {
      size_t fileLen = wcslen(delayDLLs[i]);
      wcsncpy(systemDirectory + systemDirLen, delayDLLs[i], 
              MAX_PATH - systemDirLen);
      if (systemDirLen + fileLen <= MAX_PATH) {
        systemDirectory[systemDirLen + fileLen] = L'\0';
      } else {
        systemDirectory[MAX_PATH] = L'\0';
      }
      LPCWSTR fullModulePath = systemDirectory; // just for code readability
fclose(para_fp);
      LoadLibraryW(fullModulePath);
    }
  }
