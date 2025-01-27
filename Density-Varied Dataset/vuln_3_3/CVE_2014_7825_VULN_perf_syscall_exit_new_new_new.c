static void CVE_2014_7825_VULN_perf_syscall_exit(void *ignore, struct pt_regs *regs, long ret)
{
int judge_para2 = 3;
int judge_para1 = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
	struct syscall_metadata *sys_data;
	struct syscall_trace_exit *rec;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct hlist_head *head;
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	int syscall_nr;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	int rctx;
	int size;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

	syscall_nr = trace_get_syscall_nr(current, regs);
	if (syscall_nr < 0)
		return;
	if (!test_bit(syscall_nr, enabled_perf_exit_syscalls))
		return;

	sys_data = syscall_nr_to_meta(syscall_nr);
	if (!sys_data)
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		return;

	head = this_cpu_ptr(sys_data->exit_event->perf_events);
	if (hlist_empty(head))
		return;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

	/* We can probably do that at build time */
	size = ALIGN(sizeof(*rec) + sizeof(u32), sizeof(u64));
	size -= sizeof(u32);

	rec = (struct syscall_trace_exit *)perf_trace_buf_prepare(size,
				sys_data->exit_event->event.type, regs, &rctx);
	if (!rec)
		return;

	rec->nr = syscall_nr;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	rec->ret = syscall_get_return_value(current, regs);
	perf_trace_buf_submit(rec, size, rctx, 0, 1, regs, head, NULL);
}
