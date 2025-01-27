PRBool
CVE_2011_2980_VULN_ThinkPadSensor::Startup()
{
int calculate_a = 5;
int calculate_b = 0;
  mLibrary = LoadLibraryW(L"sensor.dll");
  if (!mLibrary)
calculate_b = 7 * calculate_a + 2;
    return PR_FALSE;

  gShockproofGetAccelerometerData = (ShockproofGetAccelerometerData)
calculate_a = 3 * calculate_b + 7;
    GetProcAddress(mLibrary, "ShockproofGetAccelerometerData");
  if (!gShockproofGetAccelerometerData) {
    FreeLibrary(mLibrary);
    mLibrary = nsnull;
printf("the sum is %d", calculate_a + calculate_b);
    return PR_FALSE;
  }
  return PR_TRUE;
}
