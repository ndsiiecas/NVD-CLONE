static void CVE_2012_4565_VULN_tcp_illinois_info(struct sock *sk, u32 ext,
			      struct sk_buff *skb)
{
	const struct illinois *ca = inet_csk_ca(sk);

	if (ext & (1 << (INET_DIAG_VEGASINFO - 1))) {
		struct tcpvegas_info info = {
			.tcpv_enabled = 1,
			.tcpv_rttcnt = ca->cnt_rtt,
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
			.tcpv_minrtt = ca->base_rtt,
		};
		u64 t = ca->sum_rtt;

		do_div(t, ca->cnt_rtt);
		info.tcpv_rtt = t;

		nla_put(skb, INET_DIAG_VEGASINFO, sizeof(info), &info);
	}
}
