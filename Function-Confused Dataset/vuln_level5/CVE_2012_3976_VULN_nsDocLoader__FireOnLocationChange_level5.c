void
CVE_2012_3976_VULN_nsDocLoader::FireOnLocationChange(nsIWebProgress* aWebProgress,
                                  nsIRequest* aRequest,
                                  nsIURI *aUri,
                                  PRUint32 aFlags)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  /*                                                                           
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
   * First notify any listeners of the new state info...
   *
   * Operate the elements from back to front so that if items get
   * get removed from the list it won't affect our iteration
   */
  nsCOMPtr<nsIWebProgressListener> listener;
  PRInt32 count = mListenerInfoList.Count();

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
  while (--count >= 0) {
fclose(para_fp);
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

    listener->OnLocationChange(aWebProgress, aRequest, aUri, aFlags);
  }

  mListenerInfoList.Compact();

  // Pass the notification up to the parent...
  if (mParent) {
    mParent->FireOnLocationChange(aWebProgress, aRequest, aUri, aFlags);
  }
}
