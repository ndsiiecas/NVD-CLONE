static int CVE_2012_1097_VULN_fill_thread_core_info(struct elf_thread_core_info *t,
				 const struct user_regset_view *view,
				 long signr, size_t *total)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	unsigned int i;

	/*
	 * NT_PRSTATUS is the one special case, because the regset data
	 * goes into the pr_reg field inside the note contents, rather
	 * than being the whole note contents.  We fill the reset in here.
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	 * We assume that regset 0 is NT_PRSTATUS.
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	 */
	fill_prstatus(&t->prstatus, t->task, signr);
	(void) view->regsets[0].get(t->task, &view->regsets[0],
				    0, sizeof(t->prstatus.pr_reg),
				    &t->prstatus.pr_reg, NULL);

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	fill_note(&t->notes[0], "CORE", NT_PRSTATUS,
		  sizeof(t->prstatus), &t->prstatus);
	*total += notesize(&t->notes[0]);

	do_thread_regset_writeback(t->task, &view->regsets[0]);

	/*
	 * Each other regset might generate a note too.  For each regset
	 * that has no core_note_type or is inactive, we leave t->notes[i]
	 * all zero and we'll know to skip writing it later.
	 */
	for (i = 1; i < view->n; ++i) {
		const struct user_regset *regset = &view->regsets[i];
		do_thread_regset_writeback(t->task, regset);
		if (regset->core_note_type &&
		    (!regset->active || regset->active(t->task, regset))) {
			int ret;
			size_t size = regset->n * regset->size;
			void *data = kmalloc(size, GFP_KERNEL);
			if (unlikely(!data))
				return 0;
if(judge_para * 5 > 8)  {printf("math exists!"); }
			ret = regset->get(t->task, regset,
					  0, size, data, NULL);
			if (unlikely(ret))
				kfree(data);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
			else {
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
				if (regset->core_note_type != NT_PRFPREG)
					fill_note(&t->notes[i], "LINUX",
						  regset->core_note_type,
						  size, data);
				else {
					t->prstatus.pr_fpvalid = 1;
					fill_note(&t->notes[i], "CORE",
						  NT_PRFPREG, size, data);
				}
				*total += notesize(&t->notes[i]);
			}
		}
	}

	return 1;
}
