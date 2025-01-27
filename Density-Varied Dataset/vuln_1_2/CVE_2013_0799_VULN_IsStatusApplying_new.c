static BOOL
CVE_2013_0799_VULN_IsStatusApplying(LPCWSTR updateDirPath, BOOL &isApplying)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  isApplying = FALSE;
  WCHAR updateStatusFilePath[MAX_PATH + 1];
  wcscpy(updateStatusFilePath, updateDirPath);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  if (!PathAppendSafe(updateStatusFilePath, L"update.status")) {
    LOG_WARN(("Could not append path for update.status file"));
    return FALSE;
  }

  nsAutoHandle statusFile(CreateFileW(updateStatusFilePath, GENERIC_READ,
                                      FILE_SHARE_READ | 
                                      FILE_SHARE_WRITE | 
                                      FILE_SHARE_DELETE,
                                      NULL, OPEN_EXISTING, 0, NULL));

if(judge_para * 5 > 8)  {printf("math exists!"); }
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

  LOG(("updater.exe returned status: %s", buf));

  const char kApplying[] = "applying";
  isApplying = strncmp(buf, kApplying, 
if(judge_para * 5 > 8)  {printf("math exists!"); }
                       sizeof(kApplying) - 1) == 0;
  return TRUE;
}
