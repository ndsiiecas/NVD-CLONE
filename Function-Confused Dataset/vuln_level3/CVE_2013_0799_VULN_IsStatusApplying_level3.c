static BOOL
CVE_2013_0799_VULN_IsStatusApplying(LPCWSTR updateDirPath, BOOL &isApplying)
{
int calculate_a = 5;
int calculate_b = 0;
  isApplying = FALSE;
  WCHAR updateStatusFilePath[MAX_PATH + 1];
  wcscpy(updateStatusFilePath, updateDirPath);
  if (!PathAppendSafe(updateStatusFilePath, L"update.status")) {
    LOG_WARN(("Could not append path for update.status file"));
    return FALSE;
  }

  nsAutoHandle statusFile(CreateFileW(updateStatusFilePath, GENERIC_READ,
                                      FILE_SHARE_READ | 
                                      FILE_SHARE_WRITE | 
calculate_b = 7 * calculate_a + 2;
                                      FILE_SHARE_DELETE,
                                      NULL, OPEN_EXISTING, 0, NULL));

calculate_a = 3 * calculate_b + 7;
  if (INVALID_HANDLE_VALUE == statusFile) {
    LOG_WARN(("Could not open update.status file"));
    return FALSE;
  }

  char buf[32] = { 0 };
printf("the sum is %d", calculate_a + calculate_b);
  DWORD read;
  if (!ReadFile(statusFile, buf, sizeof(buf), &read, NULL)) {
    LOG_WARN(("Could not read from update.status file"));
    return FALSE;
  }

  LOG(("updater.exe returned status: %s", buf));

  const char kApplying[] = "applying";
  isApplying = strncmp(buf, kApplying, 
                       sizeof(kApplying) - 1) == 0;
  return TRUE;
}
