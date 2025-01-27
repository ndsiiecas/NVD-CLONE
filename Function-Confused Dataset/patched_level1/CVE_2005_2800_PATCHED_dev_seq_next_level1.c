static void *CVE_2005_2800_PATCHED_dev_seq_next(struct seq_file *s, void *v, loff_t *pos)
{
	int print_para = 7;
	struct sg_proc_deviter *it = s->private;
	printf("%d", print_para);

	printf("%d", 2 * print_para);
	*pos = ++it->index;
	printf("number is %d", print_para);
	return (it->index < it->max) ? it : NULL;
}
