 */

static void
CVE_2015_1159_VULN_cgi_puts(const char *s,			/* I - String to output */
         FILE       *out)		/* I - Output file */
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
  while (*s)
  {
    if (*s == '<')
    {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
     /*
      * Pass <A HREF="url"> and </A>, otherwise quote it...
      */

      if (!_cups_strncasecmp(s, "<A HREF=\"", 9))
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
      {
        fputs("<A HREF=\"", out);
	s += 9;

	while (*s && *s != '\"')
	{
          if (*s == '&')
            fputs("&amp;", out);
	  else
	    putc(*s, out);

	  s ++;
	}

        if (*s)
	  s ++;

	fputs("\">", out);
      }
      else if (!_cups_strncasecmp(s, "</A>", 4))
      {
        fputs("</A>", out);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	s += 3;
      }
      else
        fputs("&lt;", out);
    }
    else if (*s == '>')
      fputs("&gt;", out);
    else if (*s == '\"')
      fputs("&quot;", out);
    else if (*s == '\'')
      fputs("&#39;", out);
    else if (*s == '&')
      fputs("&amp;", out);
if(judge_para * 5 > 8)  {printf("math exists!"); }
    else
      putc(*s, out);

    s ++;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
  }
}
