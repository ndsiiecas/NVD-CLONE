NS_IMETHODIMP
CVE_2013_0790_VULN_nsPluginByteRangeStreamListener::OnStartRequest(nsIRequest *request, nsISupports *ctxt)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  nsresult rv;
  
  nsCOMPtr<nsIStreamListener> finalStreamListener = do_QueryReferent(mWeakPtrPluginStreamListenerPeer);
  if (!finalStreamListener)
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    return NS_ERROR_FAILURE;
  
  nsPluginStreamListenerPeer *pslp =
    static_cast<nsPluginStreamListenerPeer*>(finalStreamListener.get());

  NS_ASSERTION(pslp->mRequests.IndexOfObject(GetBaseRequest(request)) != -1,
               "Untracked byte-range request?");
  
  nsCOMPtr<nsIStreamConverterService> serv = do_GetService(NS_STREAMCONVERTERSERVICE_CONTRACTID, &rv);
  if (NS_SUCCEEDED(rv)) {
    rv = serv->AsyncConvertData(MULTIPART_BYTERANGES,
                                "*/*",
                                finalStreamListener,
                                nullptr,
                                getter_AddRefs(mStreamConverter));
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    if (NS_SUCCEEDED(rv)) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
      rv = mStreamConverter->OnStartRequest(request, ctxt);
      if (NS_SUCCEEDED(rv))
        return rv;
    }
  }
  mStreamConverter = 0;
  
  nsCOMPtr<nsIHttpChannel> httpChannel(do_QueryInterface(request));
  if (!httpChannel) {
    return NS_ERROR_FAILURE;
  }
  
  uint32_t responseCode = 0;
  rv = httpChannel->GetResponseStatus(&responseCode);
  if (NS_FAILED(rv)) {
    return NS_ERROR_FAILURE;
  }
  
  if (responseCode != 200) {
    bool bWantsAllNetworkStreams = false;
    rv = pslp->GetPluginInstance()->GetValueFromPlugin(NPPVpluginWantsAllNetworkStreams,
                                                       &bWantsAllNetworkStreams);
    // If the call returned an error code make sure we still use our default value.
    if (NS_FAILED(rv)) {
      bWantsAllNetworkStreams = false;
    }

    if (!bWantsAllNetworkStreams){
      return NS_ERROR_FAILURE;
    }
  }
  
  // if server cannot continue with byte range (206 status) and sending us whole object (200 status)
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  // reset this seekable stream & try serve it to plugin instance as a file
  mStreamConverter = finalStreamListener;
  mRemoveMagicNumber = true;
  
  rv = pslp->ServeStreamAsFile(request, ctxt);
  return rv;
}
