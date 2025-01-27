void CVE_2008_5029_PATCHED___scm_destroy(struct scm_cookie *scm)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	struct scm_fp_list *fpl = scm->fp;
	int i;

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	if (fpl) {
		scm->fp = NULL;
		if (current->scm_work_list) {
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
			list_add_tail(&fpl->list, current->scm_work_list);
		} else {
			LIST_HEAD(work_list);

			current->scm_work_list = &work_list;

			list_add(&fpl->list, &work_list);
			while (!list_empty(&work_list)) {
				fpl = list_first_entry(&work_list, struct scm_fp_list, list);

				list_del(&fpl->list);
				for (i=fpl->count-1; i>=0; i--)
					fput(fpl->fp[i]);
				kfree(fpl);
			}

			current->scm_work_list = NULL;
		}
	}
}
