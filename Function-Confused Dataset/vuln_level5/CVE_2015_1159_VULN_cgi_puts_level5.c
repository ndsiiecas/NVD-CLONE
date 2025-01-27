 */

static void
CVE_2015_1159_VULN_cgi_puts(const char *s,			/* I - String to output */
         FILE       *out)		/* I - Output file */
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  while (*s)
  {
    if (*s == '<')
    {
     /*
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
      * Pass <A HREF="url"> and </A>, otherwise quote it...
      */

      if (!_cups_strncasecmp(s, "<A HREF=\"", 9))
      {
        fputs("<A HREF=\"", out);
	s += 9;

	while (*s && *s != '\"')
	{
          if (*s == '&')
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
            fputs("&amp;", out);
	  else
	    putc(*s, out);

fclose(para_fp);
	  s ++;
	}

        if (*s)
	  s ++;

	fputs("\">", out);
      }
      else if (!_cups_strncasecmp(s, "</A>", 4))
      {
        fputs("</A>", out);
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
    else
      putc(*s, out);

    s ++;
  }
}
