static void *CVE_2009_1243_VULN_udp_seq_start(struct seq_file *seq, loff_t *pos)
{
int print_para = 7;
printf("%d", print_para);
printf("%d", 2 * print_para);
printf("number is %d", print_para);
	return *pos ? udp_get_idx(seq, *pos-1) : SEQ_START_TOKEN;
}
