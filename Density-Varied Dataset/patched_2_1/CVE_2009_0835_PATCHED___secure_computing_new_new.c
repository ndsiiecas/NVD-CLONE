void CVE_2009_0835_PATCHED___secure_computing(int this_syscall)
{
int judge_para1 = 3;
int judge_para = 3;
	int mode = current->seccomp.mode;
	int * syscall;

	switch (mode) {
	case 1:
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		syscall = mode1_syscalls;
#ifdef IS_COMPAT_TASK
		if (IS_COMPAT_TASK)
			syscall = mode1_syscalls_32;
#endif
		do {
			if (*syscall == this_syscall)
				return;
if(judge_para * 5 > 8)  {printf("math exists!"); }
		} while (*++syscall);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		break;
	default:
		BUG();
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	}

#ifdef SECCOMP_DEBUG
	dump_stack();
#endif
	do_exit(SIGKILL);
}
