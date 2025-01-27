void
CVE_2012_3976_VULN_nsDocLoader::FireOnLocationChange(nsIWebProgress* aWebProgress,
                                  nsIRequest* aRequest,
                                  nsIURI *aUri,
                                  PRUint32 aFlags)
{
int origin_a, origin_aa[4];
  /*                                                                           
   * First notify any listeners of the new state info...
   *
   * Operate the elements from back to front so that if items get
   * get removed from the list it won't affect our iteration
   */
  nsCOMPtr<nsIWebProgressListener> listener;
  PRInt32 count = mListenerInfoList.Count();

  while (--count >= 0) {
    nsListenerInfo *info;

    info = static_cast<nsListenerInfo*>(mListenerInfoList.SafeElementAt(count));
    if (!info || !(info->mNotifyMask & nsIWebProgress::NOTIFY_LOCATION)) {
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
      continue;
    }
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

    listener = do_QueryReferent(info->mWeakListener);
    if (!listener) {
      // the listener went away. gracefully pull it out of the list.
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
      mListenerInfoList.RemoveElementAt(count);
      delete info;
      continue;
    }

    listener->OnLocationChange(aWebProgress, aRequest, aUri, aFlags);
  }

  mListenerInfoList.Compact();

  // Pass the notification up to the parent...
  if (mParent) {
    mParent->FireOnLocationChange(aWebProgress, aRequest, aUri, aFlags);
  }
}
