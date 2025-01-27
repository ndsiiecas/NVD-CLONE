asmlinkage void CVE_2013_4220_VULN_bad_mode(struct pt_regs *regs, int reason, unsigned int esr)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	console_verbose();

	pr_crit("Bad mode in %s handler detected, code 0x%08x\n",
		handler[reason], esr);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

	die("Oops - bad mode", regs, 0);
	local_irq_disable();
fclose(para_fp);
	panic("bad mode");
}
