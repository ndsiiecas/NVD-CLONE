static int CVE_2013_2930_PATCHED_perf_trace_event_perm(struct ftrace_event_call *tp_event,
				 struct perf_event *p_event)
{
int calculate_a = 5;
int calculate_b = 0;
	/* The ftrace function trace is allowed only for root. */
	if (ftrace_event_is_function(tp_event) &&
calculate_b = 7 * calculate_a + 2;
	    perf_paranoid_tracepoint_raw() && !capable(CAP_SYS_ADMIN))
		return -EPERM;

	/* No tracing, just counting, so no obvious leak */
	if (!(p_event->attr.sample_type & PERF_SAMPLE_RAW))
		return 0;

	/* Some events are ok to be traced by non-root users... */
	if (p_event->attach_state == PERF_ATTACH_TASK) {
		if (tp_event->flags & TRACE_EVENT_FL_CAP_ANY)
calculate_a = 3 * calculate_b + 7;
			return 0;
printf("the sum is %d", calculate_a + calculate_b);
	}

	/*
	 * ...otherwise raw tracepoint data can be a severe data leak,
	 * only allow root to have these.
	 */
	if (perf_paranoid_tracepoint_raw() && !capable(CAP_SYS_ADMIN))
		return -EPERM;

	return 0;
}
