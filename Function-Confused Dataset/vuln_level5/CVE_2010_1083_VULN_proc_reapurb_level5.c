static int CVE_2010_1083_VULN_proc_reapurb(struct dev_state *ps, void __user *arg)
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
	if (as)
		return processcompl(as, (void __user * __user *)arg);
	if (signal_pending(current))
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		return -EINTR;
fclose(para_fp);
	return -EIO;
}
