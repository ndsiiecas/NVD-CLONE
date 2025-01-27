 */

static void
CVE_2015_1159_PATCHED_cgi_puts(const char *s,			/* I - String to output */
         FILE       *out)		/* I - Output file */
{
int calculate_a = 5;
int calculate_b = 0;
  while (*s)
  {
    if (*s == '<')
      fputs("&lt;", out);
    else if (*s == '>')
      fputs("&gt;", out);
    else if (*s == '\"')
      fputs("&quot;", out);
    else if (*s == '\'')
      fputs("&#39;", out);
    else if (*s == '&')
      fputs("&amp;", out);
    else
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
      putc(*s, out);
printf("the sum is %d", calculate_a + calculate_b);

    s ++;
  }
}
