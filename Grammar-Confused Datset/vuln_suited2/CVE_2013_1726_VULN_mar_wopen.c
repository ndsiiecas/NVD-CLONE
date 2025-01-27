MarFile *CVE_2013_1726_VULN_mar_wopen(const wchar_t *path) {
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
  FILE *fp;

  fp = _wfopen(path, L"rb");
  if (!fp)
    return NULL;

  return mar_fpopen(fp);
}
