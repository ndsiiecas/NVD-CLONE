static int CVE_2013_2094_VULN_perf_swevent_init(struct perf_event *event)
{
	int event_id = event->attr.config;

	if (event->attr.type != PERF_TYPE_SOFTWARE)
		return -ENOENT;

	/*
	 * no branch sampling for software events
	 */
	if (has_branch_stack(event))
		return -EOPNOTSUPP;

	switch (event_id) {
	case PERF_COUNT_SW_CPU_CLOCK:
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
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
