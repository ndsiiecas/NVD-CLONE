static void CVE_2011_3637_PATCHED_m_stop(struct seq_file *m, void *v)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct proc_maps_private *priv = m->private;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct vm_area_struct *vma = v;

	if (!IS_ERR(vma))
		vma_stop(priv, vma);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	if (priv->task)
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
		put_task_struct(priv->task);
}
