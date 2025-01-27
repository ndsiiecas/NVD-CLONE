static void CVE_2012_4565_VULN_tcp_illinois_info(struct sock *sk, u32 ext,
			      struct sk_buff *skb)
{
int origin_a, origin_aa[4];
	const struct illinois *ca = inet_csk_ca(sk);

	if (ext & (1 << (INET_DIAG_VEGASINFO - 1))) {
		struct tcpvegas_info info = {
			.tcpv_enabled = 1,
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
			.tcpv_rttcnt = ca->cnt_rtt,
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
			.tcpv_minrtt = ca->base_rtt,
		};
		u64 t = ca->sum_rtt;

		do_div(t, ca->cnt_rtt);
		info.tcpv_rtt = t;

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		nla_put(skb, INET_DIAG_VEGASINFO, sizeof(info), &info);
	}
}
