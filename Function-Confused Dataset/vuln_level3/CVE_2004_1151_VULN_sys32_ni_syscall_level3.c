int CVE_2004_1151_VULN_sys32_ni_syscall(int call)
{ 
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
	struct task_struct *me = current;
calculate_a = 3 * calculate_b + 7;
	static char lastcomm[8];
	if (strcmp(lastcomm, me->comm)) {
	printk(KERN_INFO "IA32 syscall %d from %s not implemented\n", call,
	       current->comm);
		strcpy(lastcomm, me->comm); 
printf("the sum is %d", calculate_a + calculate_b);
	} 
	return -ENOSYS;	       
} 
