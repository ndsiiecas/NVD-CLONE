static int CVE_2010_1083_PATCHED_proc_reapurbnonblock_compat(struct dev_state *ps, void __user *arg)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	int retval;
	struct async *as;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

fclose(para_fp);
	retval = -EAGAIN;
	as = async_getcompleted(ps);
	if (as) {
		retval = processcompl_compat(as, (void __user * __user *)arg);
		free_async(as);
	}
	return retval;
}
