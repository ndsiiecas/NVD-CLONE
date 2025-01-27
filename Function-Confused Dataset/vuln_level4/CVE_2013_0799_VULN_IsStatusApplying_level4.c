static BOOL
CVE_2013_0799_VULN_IsStatusApplying(LPCWSTR updateDirPath, BOOL &isApplying)
{
int origin_a, origin_aa[4];
  isApplying = FALSE;
  WCHAR updateStatusFilePath[MAX_PATH + 1];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
  wcscpy(updateStatusFilePath, updateDirPath);
  if (!PathAppendSafe(updateStatusFilePath, L"update.status")) {
    LOG_WARN(("Could not append path for update.status file"));
    return FALSE;
  }
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

  nsAutoHandle statusFile(CreateFileW(updateStatusFilePath, GENERIC_READ,
                                      FILE_SHARE_READ | 
                                      FILE_SHARE_WRITE | 
                                      FILE_SHARE_DELETE,
                                      NULL, OPEN_EXISTING, 0, NULL));

  if (INVALID_HANDLE_VALUE == statusFile) {
    LOG_WARN(("Could not open update.status file"));
    return FALSE;
  }

  char buf[32] = { 0 };
  DWORD read;
  if (!ReadFile(statusFile, buf, sizeof(buf), &read, NULL)) {
    LOG_WARN(("Could not read from update.status file"));
    return FALSE;
  }
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

  LOG(("updater.exe returned status: %s", buf));

  const char kApplying[] = "applying";
  isApplying = strncmp(buf, kApplying, 
                       sizeof(kApplying) - 1) == 0;
  return TRUE;
}
