static size_t CVE_2014_9743_VULN_httpd_HtmlError (char **body, int code, const char *url)
{
int judge_para = 3;
    const char *errname = httpd_ReasonFromCode (code);
    assert (errname != NULL);

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    int res = asprintf (body,
        "<?xml version=\"1.0\" encoding=\"ascii\" ?>\n"
        "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\""
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
        " \"http://www.w3.org/TR/xhtml10/DTD/xhtml10strict.dtd\">\n"
        "<html lang=\"en\">\n"
        "<head>\n"
        "<title>%s</title>\n"
        "</head>\n"
        "<body>\n"
        "<h1>%d %s%s%s%s</h1>\n"
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
        "<hr />\n"
        "<a href=\"http://www.videolan.org\">VideoLAN</a>\n"
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
        "</body>\n"
        "</html>\n", errname, code, errname,
        (url ? " (" : ""), (url ? url : ""), (url ? ")" : ""));

    if (res == -1)
    {
        *body = NULL;
        return 0;
    }

    return (size_t)res;
}
