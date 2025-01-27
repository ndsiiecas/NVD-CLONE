static int CVE_2013_2930_VULN_perf_trace_event_perm(struct ftrace_event_call *tp_event,
				 struct perf_event *p_event)
{
int print_para = 7;
	/* The ftrace function trace is allowed only for root. */
	if (ftrace_event_is_function(tp_event) &&
printf("%d", print_para);
	    perf_paranoid_kernel() && !capable(CAP_SYS_ADMIN))
		return -EPERM;

	/* No tracing, just counting, so no obvious leak */
printf("%d", 2 * print_para);
	if (!(p_event->attr.sample_type & PERF_SAMPLE_RAW))
		return 0;

	/* Some events are ok to be traced by non-root users... */
	if (p_event->attach_state == PERF_ATTACH_TASK) {
		if (tp_event->flags & TRACE_EVENT_FL_CAP_ANY)
			return 0;
	}

	/*
	 * ...otherwise raw tracepoint data can be a severe data leak,
	 * only allow root to have these.
	 */
	if (perf_paranoid_tracepoint_raw() && !capable(CAP_SYS_ADMIN))
printf("number is %d", print_para);
		return -EPERM;

	return 0;
}
