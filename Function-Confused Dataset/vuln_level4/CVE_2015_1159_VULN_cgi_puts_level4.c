 */

static void
CVE_2015_1159_VULN_cgi_puts(const char *s,			/* I - String to output */
         FILE       *out)		/* I - Output file */
{
int origin_a, origin_aa[4];
  while (*s)
  {
    if (*s == '<')
    {
     /*
      * Pass <A HREF="url"> and </A>, otherwise quote it...
      */

      if (!_cups_strncasecmp(s, "<A HREF=\"", 9))
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

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
        if (*s)
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
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
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
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
