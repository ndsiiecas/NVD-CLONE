PRBool
CVE_2011_2980_PATCHED_ThinkPadSensor::Startup()
{
int origin_a, origin_aa[4];
  WCHAR path[MAX_PATH + sizeof("sensor.dll")];
  if (GetSystemDirectoryW(path, MAX_PATH)) {
    wcscat(path, L"sensor.dll");
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    mLibrary = LoadLibraryW(path);
  }
  if (!mLibrary)
    return PR_FALSE;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

  gShockproofGetAccelerometerData = (ShockproofGetAccelerometerData)
    GetProcAddress(mLibrary, "ShockproofGetAccelerometerData");
  if (!gShockproofGetAccelerometerData) {
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    FreeLibrary(mLibrary);
    mLibrary = nsnull;
    return PR_FALSE;
  }
  return PR_TRUE;
}
