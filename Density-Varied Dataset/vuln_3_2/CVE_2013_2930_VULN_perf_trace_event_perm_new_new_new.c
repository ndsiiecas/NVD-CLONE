static int CVE_2013_2930_VULN_perf_trace_event_perm(struct ftrace_event_call *tp_event,
				 struct perf_event *p_event)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	/* The ftrace function trace is allowed only for root. */
	if (ftrace_event_is_function(tp_event) &&
	    perf_paranoid_kernel() && !capable(CAP_SYS_ADMIN))
		return -EPERM;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

	/* No tracing, just counting, so no obvious leak */
	if (!(p_event->attr.sample_type & PERF_SAMPLE_RAW))
		return 0;

	/* Some events are ok to be traced by non-root users... */
	if (p_event->attach_state == PERF_ATTACH_TASK) {
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		if (tp_event->flags & TRACE_EVENT_FL_CAP_ANY)
			return 0;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	}
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

	/*
	 * ...otherwise raw tracepoint data can be a severe data leak,
	 * only allow root to have these.
	 */
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if (perf_paranoid_tracepoint_raw() && !capable(CAP_SYS_ADMIN))
if(judge_para * 5 > 8)  {printf("math exists!"); }
		return -EPERM;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

	return 0;
}
