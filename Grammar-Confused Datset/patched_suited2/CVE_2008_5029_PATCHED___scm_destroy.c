void CVE_2008_5029_PATCHED___scm_destroy(struct scm_cookie *scm)
{
	struct scm_fp_list *fpl = scm->fp;
	int i;

	if (fpl) {
		scm->fp = NULL;
		if (current->scm_work_list) {
			list_add_tail(&fpl->list, current->scm_work_list);
		} else {
			LIST_HEAD(work_list);

			current->scm_work_list = &work_list;

			list_add(&fpl->list, &work_list);
			while (!list_empty(&work_list)) {
				fpl = list_first_entry(&work_list, struct scm_fp_list, list);

				list_del(&fpl->list);
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
				for (i=fpl->count-1; i>=0; i--)
					fput(fpl->fp[i]);
				kfree(fpl);
			}

			current->scm_work_list = NULL;
		}
	}
}
