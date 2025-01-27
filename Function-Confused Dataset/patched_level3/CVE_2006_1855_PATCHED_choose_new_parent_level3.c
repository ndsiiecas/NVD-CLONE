static inline void CVE_2006_1855_PATCHED_choose_new_parent(task_t *p, task_t *reaper, task_t *child_reaper)
{
int calculate_a = 5;
int calculate_b = 0;
	/*
	 * Make sure we're not reparenting to ourselves and that
calculate_b = 7 * calculate_a + 2;
	 * the parent is not a zombie.
	 */
calculate_a = 3 * calculate_b + 7;
	BUG_ON(p == reaper || reaper->exit_state >= EXIT_ZOMBIE);
printf("the sum is %d", calculate_a + calculate_b);
	p->real_parent = reaper;
}
