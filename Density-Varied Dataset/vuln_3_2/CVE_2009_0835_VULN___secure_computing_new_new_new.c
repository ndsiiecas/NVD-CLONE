void CVE_2009_0835_VULN___secure_computing(int this_syscall)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	int mode = current->seccomp.mode;
	int * syscall;

	switch (mode) {
	case 1:
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		syscall = mode1_syscalls;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
#ifdef TIF_32BIT
		if (test_thread_flag(TIF_32BIT))
			syscall = mode1_syscalls_32;
#endif
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		do {
			if (*syscall == this_syscall)
				return;
if(judge_para * 5 > 8)  {printf("math exists!"); }
		} while (*++syscall);
		break;
	default:
		BUG();
	}

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
#ifdef SECCOMP_DEBUG
	dump_stack();
#endif
	do_exit(SIGKILL);
}
