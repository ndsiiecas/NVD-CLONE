static void CVE_2014_7826_VULN_ftrace_syscall_exit(void *data, struct pt_regs *regs, long ret)
{
int origin_a, origin_aa[4];
	struct trace_array *tr = data;
	struct ftrace_event_file *ftrace_file;
	struct syscall_trace_exit *entry;
	struct syscall_metadata *sys_data;
	struct ring_buffer_event *event;
	struct ring_buffer *buffer;
	unsigned long irq_flags;
	int pc;
	int syscall_nr;

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	syscall_nr = trace_get_syscall_nr(current, regs);
	if (syscall_nr < 0)
		return;

	/* Here we're inside tp handler's rcu_read_lock_sched (__DO_TRACE()) */
	ftrace_file = rcu_dereference_sched(tr->exit_syscall_files[syscall_nr]);
	if (!ftrace_file)
		return;

	if (ftrace_trigger_soft_disabled(ftrace_file))
		return;

	sys_data = syscall_nr_to_meta(syscall_nr);
	if (!sys_data)
		return;

	local_save_flags(irq_flags);
	pc = preempt_count();
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

	buffer = tr->trace_buffer.buffer;
	event = trace_buffer_lock_reserve(buffer,
			sys_data->exit_event->event.type, sizeof(*entry),
			irq_flags, pc);
	if (!event)
		return;

	entry = ring_buffer_event_data(event);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	entry->nr = syscall_nr;
	entry->ret = syscall_get_return_value(current, regs);

	event_trigger_unlock_commit(ftrace_file, buffer, event, entry,
				    irq_flags, pc);
}
