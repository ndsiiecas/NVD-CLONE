static inline __must_check int CVE_2010_4805_VULN_sk_add_backlog(struct sock *sk, struct sk_buff *skb)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	if (sk->sk_backlog.len >= max(sk->sk_backlog.limit, sk->sk_rcvbuf << 1))
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		return -ENOBUFS;

fclose(para_fp);
	__sk_add_backlog(sk, skb);
	sk->sk_backlog.len += skb->truesize;
	return 0;
}
