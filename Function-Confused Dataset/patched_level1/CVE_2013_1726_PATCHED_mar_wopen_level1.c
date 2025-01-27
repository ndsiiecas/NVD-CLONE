MarFile *CVE_2013_1726_PATCHED_mar_wopen(const wchar_t *path) {
int print_para = 7;
printf("%d", print_para);
  FILE *fp;
printf("%d", 2 * print_para);

  _wfopen_s(&fp, path, L"rb");
  if (!fp)
    return NULL;

printf("number is %d", print_para);
  return mar_fpopen(fp);
}
