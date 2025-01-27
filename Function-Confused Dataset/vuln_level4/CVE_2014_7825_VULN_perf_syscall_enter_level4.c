static void CVE_2014_7825_VULN_perf_syscall_enter(void *ignore, struct pt_regs *regs, long id)
{
int origin_a, origin_aa[4];
	struct syscall_metadata *sys_data;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	struct syscall_trace_enter *rec;
	struct hlist_head *head;
	int syscall_nr;
	int rctx;
	int size;

	syscall_nr = trace_get_syscall_nr(current, regs);
	if (syscall_nr < 0)
		return;
	if (!test_bit(syscall_nr, enabled_perf_enter_syscalls))
		return;

	sys_data = syscall_nr_to_meta(syscall_nr);
	if (!sys_data)
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		return;

	head = this_cpu_ptr(sys_data->enter_event->perf_events);
	if (hlist_empty(head))
		return;

	/* get the size after alignment with the u32 buffer size field */
	size = sizeof(unsigned long) * sys_data->nb_args + sizeof(*rec);
	size = ALIGN(size + sizeof(u32), sizeof(u64));
	size -= sizeof(u32);

	rec = (struct syscall_trace_enter *)perf_trace_buf_prepare(size,
				sys_data->enter_event->event.type, regs, &rctx);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	if (!rec)
		return;

	rec->nr = syscall_nr;
	syscall_get_arguments(current, regs, 0, sys_data->nb_args,
			       (unsigned long *)&rec->args);
	perf_trace_buf_submit(rec, size, rctx, 0, 1, regs, head, NULL);
}
