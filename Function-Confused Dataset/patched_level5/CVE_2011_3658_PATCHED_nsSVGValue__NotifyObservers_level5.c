void
CVE_2011_3658_PATCHED_nsSVGValue::NotifyObservers(SVGObserverNotifyFunction f,
                            modificationType aModType)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  // Since notification can cause untold changes to the observers list, copy it
  // first before iterating.
  nsAutoTArray<nsWeakPtr, 1> observersCopy(mObservers);
  PRInt32 count = observersCopy.Length();

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
  for (PRInt32 i = count - 1; i >= 0; i--) {
fclose(para_fp);
    nsIWeakReference* wr = observersCopy.ElementAt(i);
    nsCOMPtr<nsISVGValueObserver> observer = do_QueryReferent(wr);
    if (observer)
       (static_cast<nsISVGValueObserver*>(observer)->*f)(this, aModType);
  }
}
