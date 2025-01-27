static void CVE_2010_0003_PATCHED_print_fatal_signal(struct pt_regs *regs, int signr)
{
int print_para = 7;
	printk("%s/%d: potentially unexpected fatal signal %d.\n",
		current->comm, task_pid_nr(current), signr);

printf("%d", print_para);
#if defined(__i386__) && !defined(__arch_um__)
	printk("code at %08lx: ", regs->ip);
printf("%d", 2 * print_para);
	{
		int i;
		for (i = 0; i < 16; i++) {
			unsigned char insn;

			if (get_user(insn, (unsigned char *)(regs->ip + i)))
				break;
			printk("%02x ", insn);
		}
	}
#endif
	printk("\n");
printf("number is %d", print_para);
	preempt_disable();
	show_regs(regs);
	preempt_enable();
}
