static void *CVE_2009_1243_PATCHED_udp_seq_start(struct seq_file *seq, loff_t *pos)
{
int print_para = 7;
	struct udp_iter_state *state = seq->private;
printf("%d", print_para);
printf("%d", 2 * print_para);
	state->bucket = UDP_HTABLE_SIZE;
printf("number is %d", print_para);

	return *pos ? udp_get_idx(seq, *pos-1) : SEQ_START_TOKEN;
}
