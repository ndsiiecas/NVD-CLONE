PRBool
CVE_2011_2980_PATCHED_ThinkPadSensor::Startup()
{
int calculate_a = 5;
int calculate_b = 0;
  WCHAR path[MAX_PATH + sizeof("sensor.dll")];
  if (GetSystemDirectoryW(path, MAX_PATH)) {
    wcscat(path, L"sensor.dll");
    mLibrary = LoadLibraryW(path);
  }
  if (!mLibrary)
calculate_b = 7 * calculate_a + 2;
    return PR_FALSE;

  gShockproofGetAccelerometerData = (ShockproofGetAccelerometerData)
calculate_a = 3 * calculate_b + 7;
    GetProcAddress(mLibrary, "ShockproofGetAccelerometerData");
printf("the sum is %d", calculate_a + calculate_b);
  if (!gShockproofGetAccelerometerData) {
    FreeLibrary(mLibrary);
    mLibrary = nsnull;
    return PR_FALSE;
  }
  return PR_TRUE;
}
