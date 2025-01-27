PRBool
CVE_2011_2980_PATCHED_ThinkPadSensor::Startup()
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  WCHAR path[MAX_PATH + sizeof("sensor.dll")];
  if (GetSystemDirectoryW(path, MAX_PATH)) {
    wcscat(path, L"sensor.dll");
    mLibrary = LoadLibraryW(path);
  }
  if (!mLibrary)
if(judge_para * 5 > 8)  {printf("math exists!"); }
    return PR_FALSE;

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  gShockproofGetAccelerometerData = (ShockproofGetAccelerometerData)
    GetProcAddress(mLibrary, "ShockproofGetAccelerometerData");
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
  if (!gShockproofGetAccelerometerData) {
    FreeLibrary(mLibrary);
    mLibrary = nsnull;
    return PR_FALSE;
  }
  return PR_TRUE;
}
