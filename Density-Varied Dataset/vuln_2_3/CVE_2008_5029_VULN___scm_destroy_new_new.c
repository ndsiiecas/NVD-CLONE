void CVE_2008_5029_VULN___scm_destroy(struct scm_cookie *scm)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	struct scm_fp_list *fpl = scm->fp;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	int i;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

	if (fpl) {
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		scm->fp = NULL;
		for (i=fpl->count-1; i>=0; i--)
			fput(fpl->fp[i]);
		kfree(fpl);
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	}
}
