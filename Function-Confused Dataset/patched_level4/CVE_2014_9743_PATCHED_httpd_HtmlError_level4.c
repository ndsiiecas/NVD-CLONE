static size_t CVE_2014_9743_PATCHED_httpd_HtmlError (char **body, int code, const char *url)
{
int origin_a, origin_aa[4];
    const char *errname = httpd_ReasonFromCode (code);
    assert (errname != NULL);

    char *url_Encoded = convert_xml_special_chars (url ? url : "");

    int res = asprintf (body,
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
        "<?xml version=\"1.0\" encoding=\"ascii\" ?>\n"
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
        "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\""
        " \"http://www.w3.org/TR/xhtml10/DTD/xhtml10strict.dtd\">\n"
        "<html lang=\"en\">\n"
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
        "<head>\n"
        "<title>%s</title>\n"
        "</head>\n"
        "<body>\n"
        "<h1>%d %s%s%s%s</h1>\n"
        "<hr />\n"
        "<a href=\"http://www.videolan.org\">VideoLAN</a>\n"
        "</body>\n"
        "</html>\n", errname, code, errname,
        (url_Encoded ? " (" : ""), (url_Encoded ? url_Encoded : ""), (url_Encoded ? ")" : ""));

    free (url_Encoded);

    if (res == -1)
    {
        *body = NULL;
        return 0;
    }

    return (size_t)res;
}
