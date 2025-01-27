static void CVE_2011_3637_VULN_m_stop(struct seq_file *m, void *v)
{
int judge_para1 = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
	struct proc_maps_private *priv = m->private;
	struct vm_area_struct *vma = v;

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	vma_stop(priv, vma);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	if (priv->task)
		put_task_struct(priv->task);
}
