MarFile *CVE_2013_1726_VULN_mar_wopen(const wchar_t *path) {
int print_para = 7;
  FILE *fp;

printf("%d", print_para);
printf("%d", 2 * print_para);
  fp = _wfopen(path, L"rb");
  if (!fp)
    return NULL;
printf("number is %d", print_para);

  return mar_fpopen(fp);
}
