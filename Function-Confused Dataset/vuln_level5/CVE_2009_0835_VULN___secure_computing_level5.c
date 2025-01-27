void CVE_2009_0835_VULN___secure_computing(int this_syscall)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	int mode = current->seccomp.mode;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
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
				return;
fclose(para_fp);
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
