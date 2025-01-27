PRBool
CVE_2011_2980_VULN_ThinkPadSensor::Startup()
{
int origin_a, origin_aa[4];
  mLibrary = LoadLibraryW(L"sensor.dll");
  if (!mLibrary)
    return PR_FALSE;

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
  gShockproofGetAccelerometerData = (ShockproofGetAccelerometerData)
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    GetProcAddress(mLibrary, "ShockproofGetAccelerometerData");
  if (!gShockproofGetAccelerometerData) {
    FreeLibrary(mLibrary);
    mLibrary = nsnull;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    return PR_FALSE;
  }
  return PR_TRUE;
}
