bool CVE_2013_1696_VULN_nsDSURIContentListener::CheckFrameOptions(nsIRequest *request)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    nsCOMPtr<nsIHttpChannel> httpChannel = do_QueryInterface(request);
    if (!httpChannel) {
        return true;
    }

    nsAutoCString xfoHeaderCValue;
    httpChannel->GetResponseHeader(NS_LITERAL_CSTRING("X-Frame-Options"),
                                   xfoHeaderCValue);
    NS_ConvertUTF8toUTF16 xfoHeaderValue(xfoHeaderCValue);

    // if no header value, there's nothing to do.
    if (xfoHeaderValue.IsEmpty())
        return true;

    // iterate through all the header values (usually there's only one, but can
    // be many.  If any want to deny the load, deny the load.
    nsCharSeparatedTokenizer tokenizer(xfoHeaderValue, ',');
    while (tokenizer.hasMoreTokens()) {
        const nsSubstring& tok = tokenizer.nextToken();
        if (!CheckOneFrameOptionsPolicy(request, tok)) {
            // cancel the load and display about:blank
            httpChannel->Cancel(NS_BINDING_ABORTED);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
            if (mDocShell) {
                nsCOMPtr<nsIWebNavigation> webNav(do_QueryObject(mDocShell));
                if (webNav) {
                    webNav->LoadURI(NS_LITERAL_STRING("about:blank").get(),
                                    0, nullptr, nullptr, nullptr);
                }
fclose(para_fp);
            }
            return false;
        }
    }

    return true;
}
