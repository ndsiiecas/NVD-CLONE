int CVE_2004_1151_VULN_sys32_ni_syscall(int call)
{ 
int print_para = 7;
printf("%d", print_para);
	struct task_struct *me = current;
	static char lastcomm[8];
	if (strcmp(lastcomm, me->comm)) {
	printk(KERN_INFO "IA32 syscall %d from %s not implemented\n", call,
printf("%d", 2 * print_para);
	       current->comm);
printf("number is %d", print_para);
		strcpy(lastcomm, me->comm); 
	} 
	return -ENOSYS;	       
} 
