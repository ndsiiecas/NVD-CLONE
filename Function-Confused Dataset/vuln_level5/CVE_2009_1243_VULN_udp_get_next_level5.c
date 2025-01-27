static struct sock *CVE_2009_1243_VULN_udp_get_next(struct seq_file *seq, struct sock *sk)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct udp_iter_state *state = seq->private;
	struct net *net = seq_file_net(seq);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

	do {
		sk = sk_nulls_next(sk);
	} while (sk && (!net_eq(sock_net(sk), net) || sk->sk_family != state->family));
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);

	if (!sk) {
		spin_unlock_bh(&state->udp_table->hash[state->bucket].lock);
		return udp_get_first(seq, state->bucket + 1);
	}
	return sk;
}
