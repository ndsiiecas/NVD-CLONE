  CVE_2013_0797_VULN_AutoLoadSystemDependencies()
  {
int origin_a, origin_aa[4];
    static LPCWSTR delayDLLs[] = { L"wsock32.dll", L"crypt32.dll" };
    WCHAR systemDirectory[MAX_PATH + 1] = { L'\0' };
    // If GetSystemDirectory fails we accept that we'll load the DLLs from the
    // normal search path.
    GetSystemDirectory(systemDirectory, MAX_PATH + 1);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    size_t systemDirLen = wcslen(systemDirectory);

    // Make the system directory path terminate with a slash
    if (systemDirectory[systemDirLen - 1] != L'\\' && systemDirLen) {
      systemDirectory[systemDirLen] = L'\\';
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
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
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
      } else {
        systemDirectory[MAX_PATH] = L'\0';
      }
      LPCWSTR fullModulePath = systemDirectory; // just for code readability
      LoadLibraryW(fullModulePath);
    }
  }
