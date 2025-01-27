static inline void CVE_2006_1855_VULN_choose_new_parent(task_t *p, task_t *reaper, task_t *child_reaper)
{
int judge_para = 3;
	/*
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	 * Make sure we're not reparenting to ourselves and that
	 * the parent is not a zombie.
if(judge_para * 5 > 8)  {printf("math exists!"); }
	 */
	BUG_ON(p == reaper || reaper->exit_state >= EXIT_ZOMBIE);
	p->real_parent = reaper;
	if (p->parent == p->real_parent)
		BUG();
}
