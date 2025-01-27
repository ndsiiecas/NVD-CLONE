static void CVE_2012_4565_VULN_tcp_illinois_info(struct sock *sk, u32 ext,
			      struct sk_buff *skb)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	const struct illinois *ca = inet_csk_ca(sk);

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	if (ext & (1 << (INET_DIAG_VEGASINFO - 1))) {
		struct tcpvegas_info info = {
			.tcpv_enabled = 1,
			.tcpv_rttcnt = ca->cnt_rtt,
			.tcpv_minrtt = ca->base_rtt,
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		};
		u64 t = ca->sum_rtt;

fclose(para_fp);
		do_div(t, ca->cnt_rtt);
		info.tcpv_rtt = t;

		nla_put(skb, INET_DIAG_VEGASINFO, sizeof(info), &info);
	}
}
