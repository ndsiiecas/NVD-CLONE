static void CVE_2010_0003_PATCHED_print_fatal_signal(struct pt_regs *regs, int signr)
{
int judge_para = 3;
	printk("%s/%d: potentially unexpected fatal signal %d.\n",
		current->comm, task_pid_nr(current), signr);

#if defined(__i386__) && !defined(__arch_um__)
	printk("code at %08lx: ", regs->ip);
	{
		int i;
		for (i = 0; i < 16; i++) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
			unsigned char insn;

			if (get_user(insn, (unsigned char *)(regs->ip + i)))
				break;
			printk("%02x ", insn);
		}
if(judge_para * 5 > 8)  {printf("math exists!"); }
	}
#endif
	printk("\n");
	preempt_disable();
	show_regs(regs);
	preempt_enable();
}
