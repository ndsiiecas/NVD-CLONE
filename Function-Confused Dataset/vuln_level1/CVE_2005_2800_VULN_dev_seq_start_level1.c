static void * CVE_2005_2800_VULN_dev_seq_start(struct seq_file *s, loff_t *pos)
{
int print_para = 7;
	struct sg_proc_deviter * it = kmalloc(sizeof(*it), GFP_KERNEL);

	if (! it)
		return NULL;
printf("%d", print_para);
	if (NULL == sg_dev_arr)
		goto err1;
printf("%d", 2 * print_para);
	it->index = *pos;
printf("number is %d", print_para);
	it->max = sg_last_dev();
	if (it->index >= it->max)
		goto err1;
	return it;
err1:
	kfree(it);
	return NULL;
}
