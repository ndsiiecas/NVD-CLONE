static void CVE_2010_0003_PATCHED_print_fatal_signal(struct pt_regs *regs, int signr)
{
int calculate_a = 5;
int calculate_b = 0;
	printk("%s/%d: potentially unexpected fatal signal %d.\n",
		current->comm, task_pid_nr(current), signr);

#if defined(__i386__) && !defined(__arch_um__)
	printk("code at %08lx: ", regs->ip);
calculate_b = 7 * calculate_a + 2;
	{
		int i;
		for (i = 0; i < 16; i++) {
			unsigned char insn;

calculate_a = 3 * calculate_b + 7;
			if (get_user(insn, (unsigned char *)(regs->ip + i)))
printf("the sum is %d", calculate_a + calculate_b);
				break;
			printk("%02x ", insn);
		}
	}
#endif
	printk("\n");
	preempt_disable();
	show_regs(regs);
	preempt_enable();
}
