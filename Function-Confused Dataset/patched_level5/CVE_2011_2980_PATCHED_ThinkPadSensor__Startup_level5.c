PRBool
CVE_2011_2980_PATCHED_ThinkPadSensor::Startup()
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  WCHAR path[MAX_PATH + sizeof("sensor.dll")];
  if (GetSystemDirectoryW(path, MAX_PATH)) {
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    wcscat(path, L"sensor.dll");
    mLibrary = LoadLibraryW(path);
  }
  if (!mLibrary)
    return PR_FALSE;

  gShockproofGetAccelerometerData = (ShockproofGetAccelerometerData)
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    GetProcAddress(mLibrary, "ShockproofGetAccelerometerData");
  if (!gShockproofGetAccelerometerData) {
    FreeLibrary(mLibrary);
    mLibrary = nsnull;
    return PR_FALSE;
fclose(para_fp);
  }
  return PR_TRUE;
}
