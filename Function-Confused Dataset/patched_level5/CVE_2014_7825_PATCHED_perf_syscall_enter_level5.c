static void CVE_2014_7825_PATCHED_perf_syscall_enter(void *ignore, struct pt_regs *regs, long id)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct syscall_metadata *sys_data;
	struct syscall_trace_enter *rec;
	struct hlist_head *head;
	int syscall_nr;
	int rctx;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	int size;

	syscall_nr = trace_get_syscall_nr(current, regs);
	if (syscall_nr < 0 || syscall_nr >= NR_syscalls)
		return;
	if (!test_bit(syscall_nr, enabled_perf_enter_syscalls))
		return;

	sys_data = syscall_nr_to_meta(syscall_nr);
	if (!sys_data)
		return;

	head = this_cpu_ptr(sys_data->enter_event->perf_events);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	if (hlist_empty(head))
		return;

	/* get the size after alignment with the u32 buffer size field */
	size = sizeof(unsigned long) * sys_data->nb_args + sizeof(*rec);
	size = ALIGN(size + sizeof(u32), sizeof(u64));
	size -= sizeof(u32);

	rec = (struct syscall_trace_enter *)perf_trace_buf_prepare(size,
fclose(para_fp);
				sys_data->enter_event->event.type, regs, &rctx);
	if (!rec)
		return;

	rec->nr = syscall_nr;
	syscall_get_arguments(current, regs, 0, sys_data->nb_args,
			       (unsigned long *)&rec->args);
	perf_trace_buf_submit(rec, size, rctx, 0, 1, regs, head, NULL);
}
