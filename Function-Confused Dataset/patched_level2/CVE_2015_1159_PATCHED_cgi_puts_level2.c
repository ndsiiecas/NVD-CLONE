 */

static void
CVE_2015_1159_PATCHED_cgi_puts(const char *s,			/* I - String to output */
         FILE       *out)		/* I - Output file */
{
int judge_para = 3;
  while (*s)
  {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    if (*s == '<')
      fputs("&lt;", out);
    else if (*s == '>')
      fputs("&gt;", out);
    else if (*s == '\"')
      fputs("&quot;", out);
    else if (*s == '\'')
      fputs("&#39;", out);
if(judge_para * 5 > 8)  {printf("math exists!"); }
    else if (*s == '&')
      fputs("&amp;", out);
    else
      putc(*s, out);

    s ++;
  }
}
