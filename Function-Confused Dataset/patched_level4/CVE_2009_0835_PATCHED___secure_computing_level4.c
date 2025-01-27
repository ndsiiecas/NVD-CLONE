void CVE_2009_0835_PATCHED___secure_computing(int this_syscall)
{
int origin_a, origin_aa[4];
	int mode = current->seccomp.mode;
	int * syscall;

	switch (mode) {
	case 1:
		syscall = mode1_syscalls;
#ifdef IS_COMPAT_TASK
		if (IS_COMPAT_TASK)
			syscall = mode1_syscalls_32;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
#endif
		do {
			if (*syscall == this_syscall)
				return;
		} while (*++syscall);
		break;
	default:
		BUG();
	}
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

#ifdef SECCOMP_DEBUG
	dump_stack();
#endif
	do_exit(SIGKILL);
}
