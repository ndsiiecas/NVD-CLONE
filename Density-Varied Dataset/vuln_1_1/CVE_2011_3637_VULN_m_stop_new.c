static void CVE_2011_3637_VULN_m_stop(struct seq_file *m, void *v)
{
int judge_para = 3;
	struct proc_maps_private *priv = m->private;
	struct vm_area_struct *vma = v;

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	vma_stop(priv, vma);
	if (priv->task)
		put_task_struct(priv->task);
}
