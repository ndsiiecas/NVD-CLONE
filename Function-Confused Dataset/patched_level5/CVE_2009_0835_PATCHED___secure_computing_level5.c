void CVE_2009_0835_PATCHED___secure_computing(int this_syscall)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	int mode = current->seccomp.mode;
	int * syscall;

	switch (mode) {
	case 1:
		syscall = mode1_syscalls;
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
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	}

#ifdef SECCOMP_DEBUG
	dump_stack();
#endif
fclose(para_fp);
	do_exit(SIGKILL);
}
