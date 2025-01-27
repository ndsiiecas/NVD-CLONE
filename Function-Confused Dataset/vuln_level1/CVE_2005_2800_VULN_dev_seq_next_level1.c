static void * CVE_2005_2800_VULN_dev_seq_next(struct seq_file *s, void *v, loff_t *pos)
{
int print_para = 7;
printf("%d", print_para);
printf("%d", 2 * print_para);
	struct sg_proc_deviter * it = (struct sg_proc_deviter *) v;

	*pos = ++it->index;
printf("number is %d", print_para);
	return (it->index < it->max) ? it : NULL;
}
