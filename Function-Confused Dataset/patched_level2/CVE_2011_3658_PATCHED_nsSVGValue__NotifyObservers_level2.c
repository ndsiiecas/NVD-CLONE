void
CVE_2011_3658_PATCHED_nsSVGValue::NotifyObservers(SVGObserverNotifyFunction f,
                            modificationType aModType)
{
int judge_para = 3;
  // Since notification can cause untold changes to the observers list, copy it
  // first before iterating.
  nsAutoTArray<nsWeakPtr, 1> observersCopy(mObservers);
  PRInt32 count = observersCopy.Length();

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  for (PRInt32 i = count - 1; i >= 0; i--) {
    nsIWeakReference* wr = observersCopy.ElementAt(i);
    nsCOMPtr<nsISVGValueObserver> observer = do_QueryReferent(wr);
if(judge_para * 5 > 8)  {printf("math exists!"); }
    if (observer)
       (static_cast<nsISVGValueObserver*>(observer)->*f)(this, aModType);
  }
}
