static struct sock *CVE_2009_1243_PATCHED_udp_get_next(struct seq_file *seq, struct sock *sk)
{
int origin_a, origin_aa[4];
	struct udp_iter_state *state = seq->private;
	struct net *net = seq_file_net(seq);

	do {
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		sk = sk_nulls_next(sk);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	} while (sk && (!net_eq(sock_net(sk), net) || sk->sk_family != state->family));
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

	if (!sk) {
		if (state->bucket < UDP_HTABLE_SIZE)
			spin_unlock_bh(&state->udp_table->hash[state->bucket].lock);
		return udp_get_first(seq, state->bucket + 1);
	}
	return sk;
}
