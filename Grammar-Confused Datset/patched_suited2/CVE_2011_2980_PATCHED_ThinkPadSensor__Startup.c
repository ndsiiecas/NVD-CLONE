PRBool
CVE_2011_2980_PATCHED_ThinkPadSensor::Startup()
{
  WCHAR path[MAX_PATH + sizeof("sensor.dll")];
  if (GetSystemDirectoryW(path, MAX_PATH)) {
    wcscat(path, L"sensor.dll");
    mLibrary = LoadLibraryW(path);
  }
  if (!mLibrary)
    return PR_FALSE;
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);

  gShockproofGetAccelerometerData = (ShockproofGetAccelerometerData)
    GetProcAddress(mLibrary, "ShockproofGetAccelerometerData");
  if (!gShockproofGetAccelerometerData) {
    FreeLibrary(mLibrary);
    mLibrary = nsnull;
    return PR_FALSE;
  }
  return PR_TRUE;
}
