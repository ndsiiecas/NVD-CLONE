static void * CVE_2005_2800_VULN_dev_seq_next(struct seq_file *s, void *v, loff_t *pos)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
	struct sg_proc_deviter * it = (struct sg_proc_deviter *) v;

calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	*pos = ++it->index;
	return (it->index < it->max) ? it : NULL;
}
