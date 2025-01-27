static void CVE_2011_3637_PATCHED_m_stop(struct seq_file *m, void *v)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct proc_maps_private *priv = m->private;
	struct vm_area_struct *vma = v;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

	if (!IS_ERR(vma))
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		vma_stop(priv, vma);
	if (priv->task)
fclose(para_fp);
		put_task_struct(priv->task);
}
