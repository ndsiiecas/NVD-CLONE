void
CVE_2011_3658_PATCHED_nsSVGValue::NotifyObservers(SVGObserverNotifyFunction f,
                            modificationType aModType)
{
int origin_a, origin_aa[4];
  // Since notification can cause untold changes to the observers list, copy it
  // first before iterating.
  nsAutoTArray<nsWeakPtr, 1> observersCopy(mObservers);
  PRInt32 count = observersCopy.Length();
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

  for (PRInt32 i = count - 1; i >= 0; i--) {
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    nsIWeakReference* wr = observersCopy.ElementAt(i);
    nsCOMPtr<nsISVGValueObserver> observer = do_QueryReferent(wr);
    if (observer)
       (static_cast<nsISVGValueObserver*>(observer)->*f)(this, aModType);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
  }
}
