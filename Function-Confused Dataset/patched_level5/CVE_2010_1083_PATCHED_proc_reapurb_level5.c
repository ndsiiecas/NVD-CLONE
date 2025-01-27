static int CVE_2010_1083_PATCHED_proc_reapurb(struct dev_state *ps, void __user *arg)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct async *as = reap_as(ps);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	if (as) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		int retval = processcompl(as, (void __user * __user *)arg);
		free_async(as);
		return retval;
	}
	if (signal_pending(current))
fclose(para_fp);
		return -EINTR;
	return -EIO;
}
