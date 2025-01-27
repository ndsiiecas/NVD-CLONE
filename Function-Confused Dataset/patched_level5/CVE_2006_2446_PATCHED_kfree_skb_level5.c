static inline void CVE_2006_2446_PATCHED_kfree_skb(struct sk_buff *skb)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	if (likely(atomic_read(&skb->users) == 1))
		smp_rmb();
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	else if (likely(!atomic_dec_and_test(&skb->users)))
fclose(para_fp);
		return;
	__kfree_skb(skb);
}
