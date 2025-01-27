static int CVE_2013_2930_PATCHED_perf_trace_event_perm(struct ftrace_event_call *tp_event,
				 struct perf_event *p_event)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	/* The ftrace function trace is allowed only for root. */
	if (ftrace_event_is_function(tp_event) &&
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	    perf_paranoid_tracepoint_raw() && !capable(CAP_SYS_ADMIN))
		return -EPERM;

	/* No tracing, just counting, so no obvious leak */
	if (!(p_event->attr.sample_type & PERF_SAMPLE_RAW))
		return 0;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

	/* Some events are ok to be traced by non-root users... */
	if (p_event->attach_state == PERF_ATTACH_TASK) {
		if (tp_event->flags & TRACE_EVENT_FL_CAP_ANY)
			return 0;
	}

	/*
	 * ...otherwise raw tracepoint data can be a severe data leak,
fclose(para_fp);
	 * only allow root to have these.
	 */
	if (perf_paranoid_tracepoint_raw() && !capable(CAP_SYS_ADMIN))
		return -EPERM;

	return 0;
}
