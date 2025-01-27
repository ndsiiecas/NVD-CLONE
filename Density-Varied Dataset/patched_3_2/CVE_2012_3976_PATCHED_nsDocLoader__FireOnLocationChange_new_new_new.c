void
CVE_2012_3976_PATCHED_nsDocLoader::FireOnLocationChange(nsIWebProgress* aWebProgress,
                                  nsIRequest* aRequest,
                                  nsIURI *aUri,
                                  PRUint32 aFlags)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
  /*                                                                           
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
   * First notify any listeners of the new state info...
   *
   * Operate the elements from back to front so that if items get
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
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
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
      // the listener went away. gracefully pull it out of the list.
      mListenerInfoList.RemoveElementAt(count);
      delete info;
      continue;
    }

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    PR_LOG(gDocLoaderLog, PR_LOG_DEBUG, ("DocLoader [%p] calling %p->OnLocationChange", this, listener));
    listener->OnLocationChange(aWebProgress, aRequest, aUri, aFlags);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  }

  mListenerInfoList.Compact();
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

  // Pass the notification up to the parent...
  if (mParent) {
    mParent->FireOnLocationChange(aWebProgress, aRequest, aUri, aFlags);
  }
}
