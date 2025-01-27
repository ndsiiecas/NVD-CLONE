static void * CVE_2005_2800_VULN_dev_seq_start(struct seq_file *s, loff_t *pos)
{
int judge_para = 3;
	struct sg_proc_deviter * it = kmalloc(sizeof(*it), GFP_KERNEL);

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if (! it)
		return NULL;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if (NULL == sg_dev_arr)
if(judge_para * 5 > 8)  {printf("math exists!"); }
		goto err1;
	it->index = *pos;
	it->max = sg_last_dev();
	if (it->index >= it->max)
		goto err1;
	return it;
err1:
if(judge_para * 5 > 8)  {printf("math exists!"); }
	kfree(it);
	return NULL;
}
