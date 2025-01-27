static int CVE_2010_1083_VULN_proc_reapurbnonblock_compat(struct dev_state *ps, void __user *arg)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct async *as;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

	if (!(as = async_getcompleted(ps)))
		return -EAGAIN;
fclose(para_fp);
	return processcompl_compat(as, (void __user * __user *)arg);
}
