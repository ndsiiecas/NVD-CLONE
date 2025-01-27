void CVE_2009_0835_VULN___secure_computing(int this_syscall)
{
int print_para = 7;
	int mode = current->seccomp.mode;
	int * syscall;

	switch (mode) {
	case 1:
		syscall = mode1_syscalls;
#ifdef TIF_32BIT
		if (test_thread_flag(TIF_32BIT))
printf("%d", print_para);
			syscall = mode1_syscalls_32;
#endif
		do {
			if (*syscall == this_syscall)
				return;
printf("%d", 2 * print_para);
		} while (*++syscall);
		break;
	default:
		BUG();
	}

#ifdef SECCOMP_DEBUG
printf("number is %d", print_para);
	dump_stack();
#endif
	do_exit(SIGKILL);
}
