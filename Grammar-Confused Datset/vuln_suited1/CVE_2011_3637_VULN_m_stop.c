static void CVE_2011_3637_VULN_m_stop(struct seq_file *m, void *v)
{
	struct proc_maps_private *priv = m->private;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	struct vm_area_struct *vma = v;

	vma_stop(priv, vma);
	if (priv->task)
		put_task_struct(priv->task);
}
