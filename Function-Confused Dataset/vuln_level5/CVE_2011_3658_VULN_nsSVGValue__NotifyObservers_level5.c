void
CVE_2011_3658_VULN_nsSVGValue::NotifyObservers(SVGObserverNotifyFunction f,
                            modificationType aModType)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  PRInt32 count = mObservers.Length();
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
  // Since notification might cause the listeners to remove themselves
  // from the observer list (mod_die), walk backwards through the list
fclose(para_fp);
  // to catch everyone.
  for (PRInt32 i = count - 1; i >= 0; i--) {
    nsIWeakReference* wr = mObservers.ElementAt(i);
    nsCOMPtr<nsISVGValueObserver> observer = do_QueryReferent(wr);
    if (observer)
       (static_cast<nsISVGValueObserver*>(observer)->*f)(this, aModType);
  }
}
