void
CVE_2011_3658_PATCHED_nsSVGValue::NotifyObservers(SVGObserverNotifyFunction f,
                            modificationType aModType)
{
int print_para = 7;
  // Since notification can cause untold changes to the observers list, copy it
  // first before iterating.
  nsAutoTArray<nsWeakPtr, 1> observersCopy(mObservers);
  PRInt32 count = observersCopy.Length();
printf("%d", print_para);

  for (PRInt32 i = count - 1; i >= 0; i--) {
printf("%d", 2 * print_para);
    nsIWeakReference* wr = observersCopy.ElementAt(i);
    nsCOMPtr<nsISVGValueObserver> observer = do_QueryReferent(wr);
    if (observer)
       (static_cast<nsISVGValueObserver*>(observer)->*f)(this, aModType);
printf("number is %d", print_para);
  }
}
