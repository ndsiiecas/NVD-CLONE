PRBool
CVE_2011_2980_PATCHED_ThinkPadSensor::Startup()
{
int judge_para = 3;
  WCHAR path[MAX_PATH + sizeof("sensor.dll")];
  if (GetSystemDirectoryW(path, MAX_PATH)) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    wcscat(path, L"sensor.dll");
if(judge_para * 5 > 8)  {printf("math exists!"); }
    mLibrary = LoadLibraryW(path);
  }
  if (!mLibrary)
    return PR_FALSE;

  gShockproofGetAccelerometerData = (ShockproofGetAccelerometerData)
    GetProcAddress(mLibrary, "ShockproofGetAccelerometerData");
  if (!gShockproofGetAccelerometerData) {
    FreeLibrary(mLibrary);
    mLibrary = nsnull;
    return PR_FALSE;
  }
  return PR_TRUE;
}
