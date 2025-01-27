static void * CVE_2005_2800_PATCHED_dev_seq_start(struct seq_file *s, loff_t *pos)
{
int judge_para2 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para1 = 3;
int judge_para = 3;
	struct sg_proc_deviter * it = kmalloc(sizeof(*it), GFP_KERNEL);

	s->private = it;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	if (! it)
		return NULL;

	if (NULL == sg_dev_arr)
		return NULL;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	it->index = *pos;
	it->max = sg_last_dev();
	if (it->index >= it->max)
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		return NULL;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	return it;
}
