void CVE_2009_0835_PATCHED___secure_computing(int this_syscall)
{
int print_para = 7;
	int mode = current->seccomp.mode;
	int * syscall;

	switch (mode) {
	case 1:
		syscall = mode1_syscalls;
printf("%d", print_para);
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
printf("%d", 2 * print_para);

#ifdef SECCOMP_DEBUG
	dump_stack();
printf("number is %d", print_para);
#endif
	do_exit(SIGKILL);
}
