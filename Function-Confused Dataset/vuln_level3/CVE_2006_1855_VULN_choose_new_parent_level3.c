static inline void CVE_2006_1855_VULN_choose_new_parent(task_t *p, task_t *reaper, task_t *child_reaper)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
	/*
	 * Make sure we're not reparenting to ourselves and that
	 * the parent is not a zombie.
calculate_a = 3 * calculate_b + 7;
	 */
printf("the sum is %d", calculate_a + calculate_b);
	BUG_ON(p == reaper || reaper->exit_state >= EXIT_ZOMBIE);
	p->real_parent = reaper;
	if (p->parent == p->real_parent)
		BUG();
}
