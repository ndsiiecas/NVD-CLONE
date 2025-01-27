void CVE_2009_0835_VULN___secure_computing(int this_syscall)
{
	int mode = current->seccomp.mode;
	int * syscall;

	switch (mode) {
	case 1:
		syscall = mode1_syscalls;
#ifdef TIF_32BIT
		if (test_thread_flag(TIF_32BIT))
			syscall = mode1_syscalls_32;
#endif
		do {
			if (*syscall == this_syscall)
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
				return;
		} while (*++syscall);
		break;
	default:
		BUG();
	}

#ifdef SECCOMP_DEBUG
	dump_stack();
#endif
	do_exit(SIGKILL);
}
