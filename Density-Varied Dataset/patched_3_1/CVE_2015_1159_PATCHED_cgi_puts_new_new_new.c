 */

static void
CVE_2015_1159_PATCHED_cgi_puts(const char *s,			/* I - String to output */
         FILE       *out)		/* I - Output file */
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
  while (*s)
  {
    if (*s == '<')
      fputs("&lt;", out);
    else if (*s == '>')
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
      fputs("&gt;", out);
    else if (*s == '\"')
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
      fputs("&quot;", out);
    else if (*s == '\'')
      fputs("&#39;", out);
    else if (*s == '&')
      fputs("&amp;", out);
    else
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
      putc(*s, out);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

    s ++;
  }
}
