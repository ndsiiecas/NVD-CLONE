static void CVE_2010_0003_VULN_print_fatal_signal(struct pt_regs *regs, int signr)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	printk("%s/%d: potentially unexpected fatal signal %d.\n",
		current->comm, task_pid_nr(current), signr);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

#if defined(__i386__) && !defined(__arch_um__)
	printk("code at %08lx: ", regs->ip);
	{
		int i;
		for (i = 0; i < 16; i++) {
			unsigned char insn;

			__get_user(insn, (unsigned char *)(regs->ip + i));
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
			printk("%02x ", insn);
		}
	}
#endif
	printk("\n");
	preempt_disable();
fclose(para_fp);
	show_regs(regs);
	preempt_enable();
}
