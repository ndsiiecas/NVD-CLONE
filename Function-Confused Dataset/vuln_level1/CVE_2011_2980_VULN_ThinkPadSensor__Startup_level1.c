PRBool
CVE_2011_2980_VULN_ThinkPadSensor::Startup()
{
int print_para = 7;
  mLibrary = LoadLibraryW(L"sensor.dll");
printf("%d", print_para);
  if (!mLibrary)
    return PR_FALSE;

printf("%d", 2 * print_para);
  gShockproofGetAccelerometerData = (ShockproofGetAccelerometerData)
    GetProcAddress(mLibrary, "ShockproofGetAccelerometerData");
  if (!gShockproofGetAccelerometerData) {
    FreeLibrary(mLibrary);
    mLibrary = nsnull;
    return PR_FALSE;
  }
printf("number is %d", print_para);
  return PR_TRUE;
}
