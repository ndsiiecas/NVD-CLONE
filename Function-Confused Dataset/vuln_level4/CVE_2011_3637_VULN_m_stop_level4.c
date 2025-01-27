static void CVE_2011_3637_VULN_m_stop(struct seq_file *m, void *v)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	struct proc_maps_private *priv = m->private;
	struct vm_area_struct *vma = v;

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	vma_stop(priv, vma);
	if (priv->task)
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		put_task_struct(priv->task);
}
