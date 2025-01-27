static size_t CVE_2014_9743_VULN_httpd_HtmlError (char **body, int code, const char *url)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    const char *errname = httpd_ReasonFromCode (code);
    assert (errname != NULL);

    int res = asprintf (body,
        "<?xml version=\"1.0\" encoding=\"ascii\" ?>\n"
        "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\""
        " \"http://www.w3.org/TR/xhtml10/DTD/xhtml10strict.dtd\">\n"
        "<html lang=\"en\">\n"
        "<head>\n"
        "<title>%s</title>\n"
        "</head>\n"
        "<body>\n"
        "<h1>%d %s%s%s%s</h1>\n"
        "<hr />\n"
        "<a href=\"http://www.videolan.org\">VideoLAN</a>\n"
        "</body>\n"
        "</html>\n", errname, code, errname,
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
        (url ? " (" : ""), (url ? url : ""), (url ? ")" : ""));

    if (res == -1)
    {
        *body = NULL;
        return 0;
    }
fclose(para_fp);

    return (size_t)res;
}
