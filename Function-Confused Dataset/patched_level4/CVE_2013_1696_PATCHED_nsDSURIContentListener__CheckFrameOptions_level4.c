bool CVE_2013_1696_PATCHED_nsDSURIContentListener::CheckFrameOptions(nsIRequest *request)
{
int origin_a, origin_aa[4];
    nsresult rv;
    nsCOMPtr<nsIChannel> chan = do_QueryInterface(request);
    if (!chan) {
      return true;
    }

    nsCOMPtr<nsIHttpChannel> httpChannel = do_QueryInterface(chan);
    if (!httpChannel) {
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
      // check if it is hiding in a multipart channel
      rv = mDocShell->GetHttpChannel(chan, getter_AddRefs(httpChannel));
      if (NS_FAILED(rv))
        return false;
    }

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
        if (!CheckOneFrameOptionsPolicy(httpChannel, tok)) {
            // cancel the load and display about:blank
            httpChannel->Cancel(NS_BINDING_ABORTED);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
            if (mDocShell) {
                nsCOMPtr<nsIWebNavigation> webNav(do_QueryObject(mDocShell));
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
                if (webNav) {
                    webNav->LoadURI(NS_LITERAL_STRING("about:blank").get(),
                                    0, nullptr, nullptr, nullptr);
                }
            }
            return false;
        }
    }

    return true;
}
