static void * CVE_2005_2800_VULN_dev_seq_next(struct seq_file *s, void *v, loff_t *pos)
{
int judge_para = 3;
	struct sg_proc_deviter * it = (struct sg_proc_deviter *) v;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	*pos = ++it->index;
if(judge_para * 5 > 8)  {printf("math exists!"); }
	return (it->index < it->max) ? it : NULL;
}
