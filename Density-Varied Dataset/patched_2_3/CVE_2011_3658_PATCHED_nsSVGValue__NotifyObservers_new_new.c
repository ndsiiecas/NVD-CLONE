void
CVE_2011_3658_PATCHED_nsSVGValue::NotifyObservers(SVGObserverNotifyFunction f,
                            modificationType aModType)
{
int judge_para1 = 3;
int judge_para = 3;
  // Since notification can cause untold changes to the observers list, copy it
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  // first before iterating.
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  nsAutoTArray<nsWeakPtr, 1> observersCopy(mObservers);
  PRInt32 count = observersCopy.Length();

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  for (PRInt32 i = count - 1; i >= 0; i--) {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    nsIWeakReference* wr = observersCopy.ElementAt(i);
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    nsCOMPtr<nsISVGValueObserver> observer = do_QueryReferent(wr);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    if (observer)
       (static_cast<nsISVGValueObserver*>(observer)->*f)(this, aModType);
  }
}
