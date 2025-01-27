MarFile *CVE_2013_1726_PATCHED_mar_wopen(const wchar_t *path) {
int judge_para2 = 3;
int judge_para1 = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
  FILE *fp;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

  _wfopen_s(&fp, path, L"rb");
  if (!fp)
    return NULL;

if(judge_para * 5 > 8)  {printf("math exists!"); }
  return mar_fpopen(fp);
}
