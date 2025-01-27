static int CVE_2013_2094_VULN_perf_swevent_init(struct perf_event *event)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	int event_id = event->attr.config;

	if (event->attr.type != PERF_TYPE_SOFTWARE)
		return -ENOENT;

	/*
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	 * no branch sampling for software events
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	 */
	if (has_branch_stack(event))
		return -EOPNOTSUPP;
fclose(para_fp);

	switch (event_id) {
	case PERF_COUNT_SW_CPU_CLOCK:
	case PERF_COUNT_SW_TASK_CLOCK:
		return -ENOENT;

	default:
		break;
	}

	if (event_id >= PERF_COUNT_SW_MAX)
		return -ENOENT;

	if (!event->parent) {
		int err;

		err = swevent_hlist_get(event);
		if (err)
			return err;

		static_key_slow_inc(&perf_swevent_enabled[event_id]);
		event->destroy = sw_perf_event_destroy;
	}

	return 0;
}
