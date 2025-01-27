 */

static void
CVE_2015_1159_PATCHED_cgi_puts(const char *s,			/* I - String to output */
         FILE       *out)		/* I - Output file */
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
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
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    else
fclose(para_fp);
      putc(*s, out);

    s ++;
  }
}
