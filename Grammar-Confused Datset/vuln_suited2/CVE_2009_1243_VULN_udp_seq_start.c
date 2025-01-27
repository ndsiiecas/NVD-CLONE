static void *CVE_2009_1243_VULN_udp_seq_start(struct seq_file *seq, loff_t *pos)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	return *pos ? udp_get_idx(seq, *pos-1) : SEQ_START_TOKEN;
}
