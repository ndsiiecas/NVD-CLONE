static void CVE_2012_4565_VULN_tcp_illinois_info(struct sock *sk, u32 ext,
			      struct sk_buff *skb)
{
int print_para = 7;
	const struct illinois *ca = inet_csk_ca(sk);

	if (ext & (1 << (INET_DIAG_VEGASINFO - 1))) {
		struct tcpvegas_info info = {
printf("%d", print_para);
			.tcpv_enabled = 1,
			.tcpv_rttcnt = ca->cnt_rtt,
			.tcpv_minrtt = ca->base_rtt,
		};
		u64 t = ca->sum_rtt;

		do_div(t, ca->cnt_rtt);
printf("%d", 2 * print_para);
		info.tcpv_rtt = t;

		nla_put(skb, INET_DIAG_VEGASINFO, sizeof(info), &info);
printf("number is %d", print_para);
	}
}
