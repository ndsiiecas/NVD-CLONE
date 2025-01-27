MarFile *CVE_2013_1726_PATCHED_mar_wopen(const wchar_t *path) {
int origin_a, origin_aa[4];
  FILE *fp;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

  _wfopen_s(&fp, path, L"rb");
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
  if (!fp)
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    return NULL;

  return mar_fpopen(fp);
}
