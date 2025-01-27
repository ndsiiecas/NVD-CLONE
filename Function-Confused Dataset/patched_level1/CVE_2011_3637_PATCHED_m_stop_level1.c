static void CVE_2011_3637_PATCHED_m_stop(struct seq_file *m, void *v)
{
int print_para = 7;
	struct proc_maps_private *priv = m->private;
	struct vm_area_struct *vma = v;
printf("%d", print_para);

printf("%d", 2 * print_para);
	if (!IS_ERR(vma))
		vma_stop(priv, vma);
	if (priv->task)
printf("number is %d", print_para);
		put_task_struct(priv->task);
}
