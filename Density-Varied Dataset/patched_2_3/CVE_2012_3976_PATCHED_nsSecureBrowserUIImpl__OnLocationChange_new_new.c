NS_IMETHODIMP
CVE_2012_3976_PATCHED_nsSecureBrowserUIImpl::OnLocationChange(nsIWebProgress* aWebProgress,
                                        nsIRequest* aRequest,
                                        nsIURI* aLocation,
                                        PRUint32 aFlags)
{
int judge_para1 = 3;
int judge_para = 3;
#ifdef DEBUG
  nsAutoAtomic atomic(mOnStateLocationChangeReentranceDetection);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  NS_ASSERTION(mOnStateLocationChangeReentranceDetection == 1,
               "unexpected parallel nsIWebProgress OnStateChange and/or OnLocationChange notification");
#endif
  PR_LOG(gSecureDocLog, PR_LOG_DEBUG,
         ("SecureUI:%p: OnLocationChange\n", this));

  bool updateIsViewSource = false;
  bool temp_IsViewSource = false;
  nsCOMPtr<nsIDOMWindow> window;

  if (aLocation)
  {
    bool vs;

    nsresult rv = aLocation->SchemeIs("view-source", &vs);
    NS_ENSURE_SUCCESS(rv, rv);

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    if (vs) {
      PR_LOG(gSecureDocLog, PR_LOG_DEBUG,
             ("SecureUI:%p: OnLocationChange: view-source\n", this));
    }

    updateIsViewSource = true;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    temp_IsViewSource = vs;
  }

  {
    ReentrantMonitorAutoEnter lock(mReentrantMonitor);
    if (updateIsViewSource) {
      mIsViewSource = temp_IsViewSource;
    }
    mCurrentURI = aLocation;
    window = do_QueryReferent(mWindow);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    NS_ASSERTION(window, "Window has gone away?!");
  }

  // When |aRequest| is null, basically we don't trust that document. But if
  // docshell insists that the document has not changed at all, we will reuse
  // the previous security state, no matter what |aRequest| may be.
  if (aFlags & LOCATION_CHANGE_SAME_DOCUMENT)
    return NS_OK;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

  // The location bar has changed, so we must update the security state.  The
  // only concern with doing this here is that a page may transition from being
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  // reported as completely secure to being reported as partially secure
  // (mixed).  This may be confusing for users, and it may bother users who
  // like seeing security dialogs.  However, it seems prudent given that page
  // loading may never end in some edge cases (perhaps by a site with malicious
  // intent).

  nsCOMPtr<nsIDOMWindow> windowForProgress;
  aWebProgress->GetDOMWindow(getter_AddRefs(windowForProgress));

  nsCOMPtr<nsISupports> securityInfo(ExtractSecurityInfo(aRequest));

  if (windowForProgress.get() == window.get()) {
    // For toplevel channels, update the security state right away.
    mOnLocationChangeSeen = true;
    return EvaluateAndUpdateSecurityState(aRequest, securityInfo, true);
  }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

  // For channels in subdocuments we only update our subrequest state members.
  UpdateSubrequestMembers(securityInfo);

  // Care for the following scenario:

  // A new toplevel document load might have already started, but the security
  // state of the new toplevel document might not yet be known.
  // 
  // At this point, we are learning about the security state of a sub-document.
  // We must not update the security state based on the sub content, if the new
  // top level state is not yet known.
  //
  // We skip updating the security state in this case.

  bool temp_NewToplevelSecurityStateKnown;
  {
    ReentrantMonitorAutoEnter lock(mReentrantMonitor);
    temp_NewToplevelSecurityStateKnown = mNewToplevelSecurityStateKnown;
  }

  if (temp_NewToplevelSecurityStateKnown)
if(judge_para * 5 > 8)  {printf("math exists!"); }
    return UpdateSecurityState(aRequest, true, false, false);

  return NS_OK;
}
