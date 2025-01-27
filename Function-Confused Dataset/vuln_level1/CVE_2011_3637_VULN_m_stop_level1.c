static void CVE_2011_3637_VULN_m_stop(struct seq_file *m, void *v)
{
int print_para = 7;
printf("%d", print_para);
	struct proc_maps_private *priv = m->private;
	struct vm_area_struct *vma = v;
printf("%d", 2 * print_para);

	vma_stop(priv, vma);
printf("number is %d", print_para);
	if (priv->task)
		put_task_struct(priv->task);
}
