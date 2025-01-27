void CVE_2008_5029_PATCHED___scm_destroy(struct scm_cookie *scm)
{
int judge_para = 3;
	struct scm_fp_list *fpl = scm->fp;
	int i;

	if (fpl) {
		scm->fp = NULL;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		if (current->scm_work_list) {
			list_add_tail(&fpl->list, current->scm_work_list);
		} else {
			LIST_HEAD(work_list);

			current->scm_work_list = &work_list;

			list_add(&fpl->list, &work_list);
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
			while (!list_empty(&work_list)) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
				fpl = list_first_entry(&work_list, struct scm_fp_list, list);

if(judge_para * 5 > 8)  {printf("math exists!"); }
				list_del(&fpl->list);
				for (i=fpl->count-1; i>=0; i--)
if(judge_para * 5 > 8)  {printf("math exists!"); }
					fput(fpl->fp[i]);
				kfree(fpl);
			}

			current->scm_work_list = NULL;
		}
	}
}
