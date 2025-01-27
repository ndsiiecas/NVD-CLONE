static int CVE_2013_2930_VULN_perf_trace_event_perm(struct ftrace_event_call *tp_event,
				 struct perf_event *p_event)
{
int origin_a, origin_aa[4];
	/* The ftrace function trace is allowed only for root. */
	if (ftrace_event_is_function(tp_event) &&
	    perf_paranoid_kernel() && !capable(CAP_SYS_ADMIN))
		return -EPERM;

	/* No tracing, just counting, so no obvious leak */
	if (!(p_event->attr.sample_type & PERF_SAMPLE_RAW))
		return 0;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

	/* Some events are ok to be traced by non-root users... */
	if (p_event->attach_state == PERF_ATTACH_TASK) {
		if (tp_event->flags & TRACE_EVENT_FL_CAP_ANY)
			return 0;
	}
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

	/*
	 * ...otherwise raw tracepoint data can be a severe data leak,
	 * only allow root to have these.
	 */
	if (perf_paranoid_tracepoint_raw() && !capable(CAP_SYS_ADMIN))
		return -EPERM;

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	return 0;
}
