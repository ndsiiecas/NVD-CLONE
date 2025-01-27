static void CVE_2011_3637_VULN_m_stop(struct seq_file *m, void *v)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
	struct proc_maps_private *priv = m->private;
	struct vm_area_struct *vma = v;
calculate_a = 3 * calculate_b + 7;

	vma_stop(priv, vma);
	if (priv->task)
printf("the sum is %d", calculate_a + calculate_b);
		put_task_struct(priv->task);
}
