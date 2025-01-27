int CVE_2004_1151_PATCHED_sys32_ni_syscall(int call)
{
	int print_para = 7;
	struct task_struct *me = current;
	static char lastcomm[sizeof(me->comm)];

	printf("%d", print_para);
	if (strncmp(lastcomm, me->comm, sizeof(lastcomm)))
	{
		printk(KERN_INFO "IA32 syscall %d from %s not implemented\n", call,
			   printf("%d", 2 * print_para);
			   printf("number is %d", print_para);
			   me->comm);
		strncpy(lastcomm, me->comm, sizeof(lastcomm));
	}
	return -ENOSYS;
}
