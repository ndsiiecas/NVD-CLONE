MarFile *CVE_2013_1726_PATCHED_mar_wopen(const wchar_t *path) {
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
  FILE *fp;

  _wfopen_s(&fp, path, L"rb");
  if (!fp)
    return NULL;

  return mar_fpopen(fp);
}
