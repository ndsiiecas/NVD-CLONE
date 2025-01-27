PRBool
CVE_2011_2980_PATCHED_ThinkPadSensor::Startup()
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  WCHAR path[MAX_PATH + sizeof("sensor.dll")];
  if (GetSystemDirectoryW(path, MAX_PATH)) {
    wcscat(path, L"sensor.dll");
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    mLibrary = LoadLibraryW(path);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
  }
  if (!mLibrary)
    return PR_FALSE;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

  gShockproofGetAccelerometerData = (ShockproofGetAccelerometerData)
    GetProcAddress(mLibrary, "ShockproofGetAccelerometerData");
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  if (!gShockproofGetAccelerometerData) {
    FreeLibrary(mLibrary);
    mLibrary = nsnull;
    return PR_FALSE;
  }
  return PR_TRUE;
}
