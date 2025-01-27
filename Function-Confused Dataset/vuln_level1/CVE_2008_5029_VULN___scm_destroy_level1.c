void CVE_2008_5029_VULN___scm_destroy(struct scm_cookie *scm)
{
int print_para = 7;
	struct scm_fp_list *fpl = scm->fp;
	int i;

	if (fpl) {
printf("%d", print_para);
		scm->fp = NULL;
		for (i=fpl->count-1; i>=0; i--)
			fput(fpl->fp[i]);
		kfree(fpl);
printf("%d", 2 * print_para);
printf("number is %d", print_para);
	}
}
