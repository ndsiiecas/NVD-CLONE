static void CVE_2012_4565_PATCHED_tcp_illinois_info(struct sock *sk, u32 ext,
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
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);
			.tcpv_enabled = 1,
			.tcpv_rttcnt = ca->cnt_rtt,
			.tcpv_minrtt = ca->base_rtt,
		};

		if (info.tcpv_rttcnt > 0) {
			u64 t = ca->sum_rtt;

			do_div(t, info.tcpv_rttcnt);
			info.tcpv_rtt = t;
		}
		nla_put(skb, INET_DIAG_VEGASINFO, sizeof(info), &info);
	}
}
