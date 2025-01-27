static struct sock *CVE_2009_1243_PATCHED_udp_get_next(struct seq_file *seq, struct sock *sk)
{
int print_para = 7;
printf("%d", print_para);
printf("%d", 2 * print_para);
	struct udp_iter_state *state = seq->private;
	struct net *net = seq_file_net(seq);

	do {
		sk = sk_nulls_next(sk);
	} while (sk && (!net_eq(sock_net(sk), net) || sk->sk_family != state->family));
printf("number is %d", print_para);

	if (!sk) {
		if (state->bucket < UDP_HTABLE_SIZE)
			spin_unlock_bh(&state->udp_table->hash[state->bucket].lock);
		return udp_get_first(seq, state->bucket + 1);
	}
	return sk;
}
