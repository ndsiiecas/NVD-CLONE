bool CVE_2013_1696_VULN_nsDSURIContentListener::CheckFrameOptions(nsIRequest *request)
{
int origin_a, origin_aa[4];
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
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
        return true;

    // iterate through all the header values (usually there's only one, but can
    // be many.  If any want to deny the load, deny the load.
    nsCharSeparatedTokenizer tokenizer(xfoHeaderValue, ',');
    while (tokenizer.hasMoreTokens()) {
        const nsSubstring& tok = tokenizer.nextToken();
        if (!CheckOneFrameOptionsPolicy(request, tok)) {
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
            // cancel the load and display about:blank
            httpChannel->Cancel(NS_BINDING_ABORTED);
            if (mDocShell) {
                nsCOMPtr<nsIWebNavigation> webNav(do_QueryObject(mDocShell));
                if (webNav) {
                    webNav->LoadURI(NS_LITERAL_STRING("about:blank").get(),
                                    0, nullptr, nullptr, nullptr);
                }
            }
            return false;
        }
    }
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

    return true;
}
