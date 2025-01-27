void
CVE_2011_3658_VULN_nsSVGValue::NotifyObservers(SVGObserverNotifyFunction f,
                            modificationType aModType)
{
  PRInt32 count = mObservers.Length();

  // Since notification might cause the listeners to remove themselves
  // from the observer list (mod_die), walk backwards through the list
  // to catch everyone.
  for (PRInt32 i = count - 1; i >= 0; i--) {
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
    nsIWeakReference* wr = mObservers.ElementAt(i);
    nsCOMPtr<nsISVGValueObserver> observer = do_QueryReferent(wr);
    if (observer)
       (static_cast<nsISVGValueObserver*>(observer)->*f)(this, aModType);
  }
}
