void CVE_2008_5029_PATCHED___scm_destroy(struct scm_cookie *scm)
{
int judge_para1 = 3;
int judge_para = 3;
	struct scm_fp_list *fpl = scm->fp;
	int i;

	if (fpl) {
		scm->fp = NULL;
		if (current->scm_work_list) {
			list_add_tail(&fpl->list, current->scm_work_list);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		} else {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
			LIST_HEAD(work_list);

			current->scm_work_list = &work_list;

			list_add(&fpl->list, &work_list);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
			while (!list_empty(&work_list)) {
				fpl = list_first_entry(&work_list, struct scm_fp_list, list);

				list_del(&fpl->list);
				for (i=fpl->count-1; i>=0; i--)
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
					fput(fpl->fp[i]);
				kfree(fpl);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			}

			current->scm_work_list = NULL;
		}
	}
}
