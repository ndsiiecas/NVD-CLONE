static void CVE_2012_4565_PATCHED_tcp_illinois_info(struct sock *sk, u32 ext,
			      struct sk_buff *skb)
{
int print_para = 7;
	const struct illinois *ca = inet_csk_ca(sk);

	if (ext & (1 << (INET_DIAG_VEGASINFO - 1))) {
		struct tcpvegas_info info = {
			.tcpv_enabled = 1,
			.tcpv_rttcnt = ca->cnt_rtt,
			.tcpv_minrtt = ca->base_rtt,
		};

printf("%d", print_para);
		if (info.tcpv_rttcnt > 0) {
			u64 t = ca->sum_rtt;

printf("%d", 2 * print_para);
			do_div(t, info.tcpv_rttcnt);
			info.tcpv_rtt = t;
		}
printf("number is %d", print_para);
		nla_put(skb, INET_DIAG_VEGASINFO, sizeof(info), &info);
	}
}
