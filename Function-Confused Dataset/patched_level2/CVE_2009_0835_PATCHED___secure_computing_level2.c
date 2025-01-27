void CVE_2009_0835_PATCHED___secure_computing(int this_syscall)
{
int judge_para = 3;
	int mode = current->seccomp.mode;
	int * syscall;

	switch (mode) {
	case 1:
		syscall = mode1_syscalls;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
#ifdef IS_COMPAT_TASK
		if (IS_COMPAT_TASK)
			syscall = mode1_syscalls_32;
#endif
		do {
			if (*syscall == this_syscall)
				return;
		} while (*++syscall);
		break;
	default:
		BUG();
	}

#ifdef SECCOMP_DEBUG
	dump_stack();
if(judge_para * 5 > 8)  {printf("math exists!"); }
#endif
	do_exit(SIGKILL);
}
