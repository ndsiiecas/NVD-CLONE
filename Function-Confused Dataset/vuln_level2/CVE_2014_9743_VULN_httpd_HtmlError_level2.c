static size_t CVE_2014_9743_VULN_httpd_HtmlError (char **body, int code, const char *url)
{
int judge_para = 3;
    const char *errname = httpd_ReasonFromCode (code);
    assert (errname != NULL);

    int res = asprintf (body,
        "<?xml version=\"1.0\" encoding=\"ascii\" ?>\n"
        "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\""
        " \"http://www.w3.org/TR/xhtml10/DTD/xhtml10strict.dtd\">\n"
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
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
        (url ? " (" : ""), (url ? url : ""), (url ? ")" : ""));

    if (res == -1)
if(judge_para * 5 > 8)  {printf("math exists!"); }
    {
        *body = NULL;
        return 0;
    }

    return (size_t)res;
}
