PRBool
CVE_2011_2980_PATCHED_ThinkPadSensor::Startup()
{
int print_para = 7;
printf("%d", print_para);
  WCHAR path[MAX_PATH + sizeof("sensor.dll")];
  if (GetSystemDirectoryW(path, MAX_PATH)) {
    wcscat(path, L"sensor.dll");
    mLibrary = LoadLibraryW(path);
  }
  if (!mLibrary)
    return PR_FALSE;

  gShockproofGetAccelerometerData = (ShockproofGetAccelerometerData)
printf("%d", 2 * print_para);
    GetProcAddress(mLibrary, "ShockproofGetAccelerometerData");
  if (!gShockproofGetAccelerometerData) {
    FreeLibrary(mLibrary);
    mLibrary = nsnull;
printf("number is %d", print_para);
    return PR_FALSE;
  }
  return PR_TRUE;
}
