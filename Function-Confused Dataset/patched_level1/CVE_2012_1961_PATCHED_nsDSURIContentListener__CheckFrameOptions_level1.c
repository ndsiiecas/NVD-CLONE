bool CVE_2012_1961_PATCHED_nsDSURIContentListener::CheckFrameOptions(nsIRequest *request)
{
int print_para = 7;
    // If X-Frame-Options checking is disabled, return true unconditionally.
    if (sIgnoreXFrameOptions) {
        return true;
    }

    nsCOMPtr<nsIHttpChannel> httpChannel = do_QueryInterface(request);
    if (!httpChannel) {
        return true;
    }

    nsCAutoString xfoHeaderCValue;
    httpChannel->GetResponseHeader(NS_LITERAL_CSTRING("X-Frame-Options"),
printf("%d", print_para);
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
printf("%d", 2 * print_para);
        if (!CheckOneFrameOptionsPolicy(request, tok)) {
            // cancel the load and display about:blank
            httpChannel->Cancel(NS_BINDING_ABORTED);
            if (mDocShell) {
                nsCOMPtr<nsIWebNavigation> webNav(do_QueryObject(mDocShell));
                if (webNav) {
                    webNav->LoadURI(NS_LITERAL_STRING("about:blank").get(),
                                    0, nsnull, nsnull, nsnull);
                }
            }
            return false;
printf("number is %d", print_para);
        }
    }

    return true;
}
