static inline void CVE_2006_2446_VULN_kfree_skb(struct sk_buff *skb)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	if (atomic_read(&skb->users) == 1 || atomic_dec_and_test(&skb->users))
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);
		__kfree_skb(skb);
}
