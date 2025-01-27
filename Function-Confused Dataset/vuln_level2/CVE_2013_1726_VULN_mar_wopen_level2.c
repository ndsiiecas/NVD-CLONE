MarFile *CVE_2013_1726_VULN_mar_wopen(const wchar_t *path) {
int judge_para = 3;
  FILE *fp;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

  fp = _wfopen(path, L"rb");
  if (!fp)
    return NULL;
if(judge_para * 5 > 8)  {printf("math exists!"); }

  return mar_fpopen(fp);
}
