void CVE_2008_5029_VULN___scm_destroy(struct scm_cookie *scm)
{
int calculate_a = 5;
int calculate_b = 0;
	struct scm_fp_list *fpl = scm->fp;
	int i;

calculate_b = 7 * calculate_a + 2;
	if (fpl) {
		scm->fp = NULL;
		for (i=fpl->count-1; i>=0; i--)
calculate_a = 3 * calculate_b + 7;
			fput(fpl->fp[i]);
printf("the sum is %d", calculate_a + calculate_b);
		kfree(fpl);
	}
}
