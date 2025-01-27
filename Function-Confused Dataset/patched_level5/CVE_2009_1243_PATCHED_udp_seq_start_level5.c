static void *CVE_2009_1243_PATCHED_udp_seq_start(struct seq_file *seq, loff_t *pos)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct udp_iter_state *state = seq->private;
	state->bucket = UDP_HTABLE_SIZE;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

fclose(para_fp);
	return *pos ? udp_get_idx(seq, *pos-1) : SEQ_START_TOKEN;
}
