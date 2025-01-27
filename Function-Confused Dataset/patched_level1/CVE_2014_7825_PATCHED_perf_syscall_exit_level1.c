static void CVE_2014_7825_PATCHED_perf_syscall_exit(void *ignore, struct pt_regs *regs, long ret)
{
int print_para = 7;
	struct syscall_metadata *sys_data;
	struct syscall_trace_exit *rec;
	struct hlist_head *head;
	int syscall_nr;
	int rctx;
	int size;

	syscall_nr = trace_get_syscall_nr(current, regs);
	if (syscall_nr < 0 || syscall_nr >= NR_syscalls)
		return;
	if (!test_bit(syscall_nr, enabled_perf_exit_syscalls))
		return;

	sys_data = syscall_nr_to_meta(syscall_nr);
	if (!sys_data)
printf("%d", print_para);
		return;

	head = this_cpu_ptr(sys_data->exit_event->perf_events);
	if (hlist_empty(head))
		return;

	/* We can probably do that at build time */
	size = ALIGN(sizeof(*rec) + sizeof(u32), sizeof(u64));
printf("%d", 2 * print_para);
	size -= sizeof(u32);

	rec = (struct syscall_trace_exit *)perf_trace_buf_prepare(size,
				sys_data->exit_event->event.type, regs, &rctx);
	if (!rec)
		return;

printf("number is %d", print_para);
	rec->nr = syscall_nr;
	rec->ret = syscall_get_return_value(current, regs);
	perf_trace_buf_submit(rec, size, rctx, 0, 1, regs, head, NULL);
}
