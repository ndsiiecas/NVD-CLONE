void CVE_2008_5029_VULN___scm_destroy(struct scm_cookie *scm)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct scm_fp_list *fpl = scm->fp;
	int i;

	if (fpl) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		scm->fp = NULL;
if(judge_para * 5 > 8)  {printf("math exists!"); }
		for (i=fpl->count-1; i>=0; i--)
if(judge_para * 5 > 8)  {printf("math exists!"); }
			fput(fpl->fp[i]);
		kfree(fpl);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	}
}
