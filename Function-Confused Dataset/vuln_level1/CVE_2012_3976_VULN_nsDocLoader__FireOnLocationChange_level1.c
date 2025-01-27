void
CVE_2012_3976_VULN_nsDocLoader::FireOnLocationChange(nsIWebProgress* aWebProgress,
                                  nsIRequest* aRequest,
                                  nsIURI *aUri,
                                  PRUint32 aFlags)
{
int print_para = 7;
  /*                                                                           
   * First notify any listeners of the new state info...
   *
   * Operate the elements from back to front so that if items get
   * get removed from the list it won't affect our iteration
   */
  nsCOMPtr<nsIWebProgressListener> listener;
  PRInt32 count = mListenerInfoList.Count();

printf("%d", print_para);
  while (--count >= 0) {
    nsListenerInfo *info;

    info = static_cast<nsListenerInfo*>(mListenerInfoList.SafeElementAt(count));
printf("%d", 2 * print_para);
    if (!info || !(info->mNotifyMask & nsIWebProgress::NOTIFY_LOCATION)) {
      continue;
    }

    listener = do_QueryReferent(info->mWeakListener);
    if (!listener) {
printf("number is %d", print_para);
      // the listener went away. gracefully pull it out of the list.
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
