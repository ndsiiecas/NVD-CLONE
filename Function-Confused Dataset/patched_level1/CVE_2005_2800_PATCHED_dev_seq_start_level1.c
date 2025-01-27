static void * CVE_2005_2800_PATCHED_dev_seq_start(struct seq_file *s, loff_t *pos)
{
int print_para = 7;
	struct sg_proc_deviter * it = kmalloc(sizeof(*it), GFP_KERNEL);
printf("%d", print_para);

	s->private = it;
	if (! it)
		return NULL;
printf("%d", 2 * print_para);
printf("number is %d", print_para);

	if (NULL == sg_dev_arr)
		return NULL;
	it->index = *pos;
	it->max = sg_last_dev();
	if (it->index >= it->max)
		return NULL;
	return it;
}
