void
CVE_2011_3658_VULN_nsSVGValue::NotifyObservers(SVGObserverNotifyFunction f,
                            modificationType aModType)
{
int judge_para2 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para1 = 3;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  PRInt32 count = mObservers.Length();
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  // Since notification might cause the listeners to remove themselves
  // from the observer list (mod_die), walk backwards through the list
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  // to catch everyone.
  for (PRInt32 i = count - 1; i >= 0; i--) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
    nsIWeakReference* wr = mObservers.ElementAt(i);
    nsCOMPtr<nsISVGValueObserver> observer = do_QueryReferent(wr);
    if (observer)
       (static_cast<nsISVGValueObserver*>(observer)->*f)(this, aModType);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
  }
}
