PRBool
CVE_2011_2980_VULN_ThinkPadSensor::Startup()
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  mLibrary = LoadLibraryW(L"sensor.dll");
  if (!mLibrary)
    return PR_FALSE;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

  gShockproofGetAccelerometerData = (ShockproofGetAccelerometerData)
    GetProcAddress(mLibrary, "ShockproofGetAccelerometerData");
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
  if (!gShockproofGetAccelerometerData) {
    FreeLibrary(mLibrary);
fclose(para_fp);
    mLibrary = nsnull;
    return PR_FALSE;
  }
  return PR_TRUE;
}
