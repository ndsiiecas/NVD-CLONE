MarFile *CVE_2013_1726_VULN_mar_wopen(const wchar_t *path) {
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
  FILE *fp;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
  fp = _wfopen(path, L"rb");
  if (!fp)
    return NULL;

  return mar_fpopen(fp);
}
