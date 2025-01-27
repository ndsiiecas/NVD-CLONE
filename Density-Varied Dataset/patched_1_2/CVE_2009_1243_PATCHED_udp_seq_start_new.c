static void *CVE_2009_1243_PATCHED_udp_seq_start(struct seq_file *seq, loff_t *pos)
{
int judge_para = 3;
	struct udp_iter_state *state = seq->private;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	state->bucket = UDP_HTABLE_SIZE;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	return *pos ? udp_get_idx(seq, *pos-1) : SEQ_START_TOKEN;
}
