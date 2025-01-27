static void * CVE_2005_2800_VULN_dev_seq_start(struct seq_file *s, loff_t *pos)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	struct sg_proc_deviter * it = kmalloc(sizeof(*it), GFP_KERNEL);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if (! it)
		return NULL;
	if (NULL == sg_dev_arr)
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
		goto err1;
	it->index = *pos;
	it->max = sg_last_dev();
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	if (it->index >= it->max)
		goto err1;
	return it;
err1:
	kfree(it);
	return NULL;
}
