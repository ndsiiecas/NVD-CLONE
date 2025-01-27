void CVE_2008_5029_PATCHED___scm_destroy(struct scm_cookie *scm)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	struct scm_fp_list *fpl = scm->fp;
	int i;

	if (fpl) {
		scm->fp = NULL;
		if (current->scm_work_list) {
			list_add_tail(&fpl->list, current->scm_work_list);
		} else {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
			LIST_HEAD(work_list);

			current->scm_work_list = &work_list;

			list_add(&fpl->list, &work_list);
			while (!list_empty(&work_list)) {
				fpl = list_first_entry(&work_list, struct scm_fp_list, list);

				list_del(&fpl->list);
				for (i=fpl->count-1; i>=0; i--)
fclose(para_fp);
					fput(fpl->fp[i]);
				kfree(fpl);
			}

			current->scm_work_list = NULL;
		}
	}
}
