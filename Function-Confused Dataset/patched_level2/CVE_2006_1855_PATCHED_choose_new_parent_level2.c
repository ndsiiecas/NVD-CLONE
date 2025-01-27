static inline void CVE_2006_1855_PATCHED_choose_new_parent(task_t *p, task_t *reaper, task_t *child_reaper)
{
int judge_para = 3;
	/*
	 * Make sure we're not reparenting to ourselves and that
	 * the parent is not a zombie.
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	 */
	BUG_ON(p == reaper || reaper->exit_state >= EXIT_ZOMBIE);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	p->real_parent = reaper;
}
