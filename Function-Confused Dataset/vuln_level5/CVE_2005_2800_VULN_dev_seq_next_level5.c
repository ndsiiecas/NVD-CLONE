static void * CVE_2005_2800_VULN_dev_seq_next(struct seq_file *s, void *v, loff_t *pos)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct sg_proc_deviter * it = (struct sg_proc_deviter *) v;

	*pos = ++it->index;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);
	return (it->index < it->max) ? it : NULL;
}
