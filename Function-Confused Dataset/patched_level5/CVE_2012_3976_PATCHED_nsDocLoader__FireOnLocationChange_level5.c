void
CVE_2012_3976_PATCHED_nsDocLoader::FireOnLocationChange(nsIWebProgress* aWebProgress,
                                  nsIRequest* aRequest,
                                  nsIURI *aUri,
                                  PRUint32 aFlags)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  /*                                                                           
   * First notify any listeners of the new state info...
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
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
      continue;
    }

    listener = do_QueryReferent(info->mWeakListener);
    if (!listener) {
      // the listener went away. gracefully pull it out of the list.
      mListenerInfoList.RemoveElementAt(count);
      delete info;
      continue;
    }

    PR_LOG(gDocLoaderLog, PR_LOG_DEBUG, ("DocLoader [%p] calling %p->OnLocationChange", this, listener));
    listener->OnLocationChange(aWebProgress, aRequest, aUri, aFlags);
  }

  mListenerInfoList.Compact();

  // Pass the notification up to the parent...
  if (mParent) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);
    mParent->FireOnLocationChange(aWebProgress, aRequest, aUri, aFlags);
  }
}
