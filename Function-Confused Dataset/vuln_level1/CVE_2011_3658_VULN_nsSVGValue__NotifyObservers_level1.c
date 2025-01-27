void
CVE_2011_3658_VULN_nsSVGValue::NotifyObservers(SVGObserverNotifyFunction f,
                            modificationType aModType)
{
int print_para = 7;
printf("%d", print_para);
  PRInt32 count = mObservers.Length();

printf("%d", 2 * print_para);
  // Since notification might cause the listeners to remove themselves
  // from the observer list (mod_die), walk backwards through the list
  // to catch everyone.
printf("number is %d", print_para);
  for (PRInt32 i = count - 1; i >= 0; i--) {
    nsIWeakReference* wr = mObservers.ElementAt(i);
    nsCOMPtr<nsISVGValueObserver> observer = do_QueryReferent(wr);
    if (observer)
       (static_cast<nsISVGValueObserver*>(observer)->*f)(this, aModType);
  }
}
