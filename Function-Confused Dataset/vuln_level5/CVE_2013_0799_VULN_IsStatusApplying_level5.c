static BOOL
CVE_2013_0799_VULN_IsStatusApplying(LPCWSTR updateDirPath, BOOL &isApplying)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  isApplying = FALSE;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
  WCHAR updateStatusFilePath[MAX_PATH + 1];
  wcscpy(updateStatusFilePath, updateDirPath);
  if (!PathAppendSafe(updateStatusFilePath, L"update.status")) {
    LOG_WARN(("Could not append path for update.status file"));
    return FALSE;
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
fclose(para_fp);

  LOG(("updater.exe returned status: %s", buf));

  const char kApplying[] = "applying";
  isApplying = strncmp(buf, kApplying, 
                       sizeof(kApplying) - 1) == 0;
  return TRUE;
}
