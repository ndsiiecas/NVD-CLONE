void
CVE_2011_3658_VULN_nsSVGValue::NotifyObservers(SVGObserverNotifyFunction f,
                            modificationType aModType)
{
int judge_para = 3;
  PRInt32 count = mObservers.Length();

  // Since notification might cause the listeners to remove themselves
  // from the observer list (mod_die), walk backwards through the list
  // to catch everyone.
  for (PRInt32 i = count - 1; i >= 0; i--) {
    nsIWeakReference* wr = mObservers.ElementAt(i);
    nsCOMPtr<nsISVGValueObserver> observer = do_QueryReferent(wr);
    if (observer)
       (static_cast<nsISVGValueObserver*>(observer)->*f)(this, aModType);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
  }
}
