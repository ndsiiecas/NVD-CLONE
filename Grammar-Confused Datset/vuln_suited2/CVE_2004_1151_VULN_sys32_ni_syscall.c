int CVE_2004_1151_VULN_sys32_ni_syscall(int call)
{ 
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	struct task_struct *me = current;
	static char lastcomm[8];
	if (strcmp(lastcomm, me->comm)) {
	printk(KERN_INFO "IA32 syscall %d from %s not implemented\n", call,
	       current->comm);
		strcpy(lastcomm, me->comm); 
	} 
	return -ENOSYS;	       
} 
