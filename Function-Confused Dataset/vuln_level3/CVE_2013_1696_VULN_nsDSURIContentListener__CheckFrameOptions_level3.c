bool CVE_2013_1696_VULN_nsDSURIContentListener::CheckFrameOptions(nsIRequest *request)
{
int calculate_a = 5;
int calculate_b = 0;
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
calculate_b = 7 * calculate_a + 2;
            if (mDocShell) {
                nsCOMPtr<nsIWebNavigation> webNav(do_QueryObject(mDocShell));
                if (webNav) {
                    webNav->LoadURI(NS_LITERAL_STRING("about:blank").get(),
                                    0, nullptr, nullptr, nullptr);
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
                }
            }
            return false;
        }
    }

    return true;
}
