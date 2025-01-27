static inline void CVE_2006_1855_VULN_choose_new_parent(task_t *p, task_t *reaper, task_t *child_reaper)
{
int print_para = 7;
	/*
	 * Make sure we're not reparenting to ourselves and that
	 * the parent is not a zombie.
printf("%d", print_para);
	 */
printf("%d", 2 * print_para);
	BUG_ON(p == reaper || reaper->exit_state >= EXIT_ZOMBIE);
	p->real_parent = reaper;
printf("number is %d", print_para);
	if (p->parent == p->real_parent)
		BUG();
}
