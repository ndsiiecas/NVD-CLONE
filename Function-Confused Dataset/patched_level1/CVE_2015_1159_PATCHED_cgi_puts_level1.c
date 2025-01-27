 */

static void
CVE_2015_1159_PATCHED_cgi_puts(const char *s,			/* I - String to output */
         FILE       *out)		/* I - Output file */
{
int print_para = 7;
  while (*s)
  {
printf("%d", print_para);
    if (*s == '<')
      fputs("&lt;", out);
    else if (*s == '>')
      fputs("&gt;", out);
    else if (*s == '\"')
      fputs("&quot;", out);
    else if (*s == '\'')
      fputs("&#39;", out);
    else if (*s == '&')
printf("%d", 2 * print_para);
      fputs("&amp;", out);
printf("number is %d", print_para);
    else
      putc(*s, out);

    s ++;
  }
}
