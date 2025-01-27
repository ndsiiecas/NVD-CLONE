bool CVE_2013_1696_PATCHED_nsDSURIContentListener::CheckFrameOptions(nsIRequest *request)
{
int judge_para1 = 3;
int judge_para = 3;
    nsresult rv;
    nsCOMPtr<nsIChannel> chan = do_QueryInterface(request);
    if (!chan) {
      return true;
    }

    nsCOMPtr<nsIHttpChannel> httpChannel = do_QueryInterface(chan);
    if (!httpChannel) {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
      // check if it is hiding in a multipart channel
      rv = mDocShell->GetHttpChannel(chan, getter_AddRefs(httpChannel));
      if (NS_FAILED(rv))
        return false;
    }

    if (!httpChannel) {
        return true;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    }

    nsAutoCString xfoHeaderCValue;
    httpChannel->GetResponseHeader(NS_LITERAL_CSTRING("X-Frame-Options"),
                                   xfoHeaderCValue);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    NS_ConvertUTF8toUTF16 xfoHeaderValue(xfoHeaderCValue);

    // if no header value, there's nothing to do.
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    if (xfoHeaderValue.IsEmpty())
        return true;

    // iterate through all the header values (usually there's only one, but can
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    // be many.  If any want to deny the load, deny the load.
    nsCharSeparatedTokenizer tokenizer(xfoHeaderValue, ',');
    while (tokenizer.hasMoreTokens()) {
        const nsSubstring& tok = tokenizer.nextToken();
        if (!CheckOneFrameOptionsPolicy(httpChannel, tok)) {
            // cancel the load and display about:blank
            httpChannel->Cancel(NS_BINDING_ABORTED);
            if (mDocShell) {
                nsCOMPtr<nsIWebNavigation> webNav(do_QueryObject(mDocShell));
                if (webNav) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
                    webNav->LoadURI(NS_LITERAL_STRING("about:blank").get(),
                                    0, nullptr, nullptr, nullptr);
                }
            }
            return false;
        }
    }

    return true;
}
