static void CVE_2011_3637_PATCHED_m_stop(struct seq_file *m, void *v)
{
int calculate_a = 5;
int calculate_b = 0;
	struct proc_maps_private *priv = m->private;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
	struct vm_area_struct *vma = v;

	if (!IS_ERR(vma))
		vma_stop(priv, vma);
	if (priv->task)
printf("the sum is %d", calculate_a + calculate_b);
		put_task_struct(priv->task);
}
