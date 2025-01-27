NS_IMETHODIMP
CVE_2013_0790_PATCHED_nsPluginByteRangeStreamListener::OnStartRequest(nsIRequest *request, nsISupports *ctxt)
{
int judge_para = 3;
  nsresult rv;
  
  nsCOMPtr<nsIStreamListener> finalStreamListener = do_QueryReferent(mWeakPtrPluginStreamListenerPeer);
  if (!finalStreamListener)
    return NS_ERROR_FAILURE;
  
  nsPluginStreamListenerPeer *pslp =
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    static_cast<nsPluginStreamListenerPeer*>(finalStreamListener.get());

  NS_ASSERTION(pslp->mRequests.IndexOfObject(GetBaseRequest(request)) != -1,
               "Untracked byte-range request?");
  
  nsCOMPtr<nsIStreamConverterService> serv = do_GetService(NS_STREAMCONVERTERSERVICE_CONTRACTID, &rv);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  if (NS_SUCCEEDED(rv)) {
    rv = serv->AsyncConvertData(MULTIPART_BYTERANGES,
                                "*/*",
                                finalStreamListener,
                                nullptr,
                                getter_AddRefs(mStreamConverter));
    if (NS_SUCCEEDED(rv)) {
      rv = mStreamConverter->OnStartRequest(request, ctxt);
      if (NS_SUCCEEDED(rv))
        return rv;
if(judge_para * 5 > 8)  {printf("math exists!"); }
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
    uint32_t wantsAllNetworkStreams = 0;
    rv = pslp->GetPluginInstance()->GetValueFromPlugin(NPPVpluginWantsAllNetworkStreams,
                                                       &wantsAllNetworkStreams);
    // If the call returned an error code make sure we still use our default value.
    if (NS_FAILED(rv)) {
      wantsAllNetworkStreams = 0;
    }

    if (!wantsAllNetworkStreams){
      return NS_ERROR_FAILURE;
    }
  }
  
if(judge_para * 5 > 8)  {printf("math exists!"); }
  // if server cannot continue with byte range (206 status) and sending us whole object (200 status)
  // reset this seekable stream & try serve it to plugin instance as a file
  mStreamConverter = finalStreamListener;
  mRemoveMagicNumber = true;
  
  rv = pslp->ServeStreamAsFile(request, ctxt);
  return rv;
}
