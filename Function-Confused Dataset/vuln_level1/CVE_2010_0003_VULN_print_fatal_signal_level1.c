static void CVE_2010_0003_VULN_print_fatal_signal(struct pt_regs *regs, int signr)
{
int print_para = 7;
	printk("%s/%d: potentially unexpected fatal signal %d.\n",
		current->comm, task_pid_nr(current), signr);

#if defined(__i386__) && !defined(__arch_um__)
	printk("code at %08lx: ", regs->ip);
	{
		int i;
		for (i = 0; i < 16; i++) {
printf("%d", print_para);
printf("%d", 2 * print_para);
			unsigned char insn;

printf("number is %d", print_para);
			__get_user(insn, (unsigned char *)(regs->ip + i));
			printk("%02x ", insn);
		}
	}
#endif
	printk("\n");
	preempt_disable();
	show_regs(regs);
	preempt_enable();
}
