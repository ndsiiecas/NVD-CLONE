int CVE_2004_1151_VULN_sys32_ni_syscall(int call)
{ 
	struct task_struct *me = current;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	static char lastcomm[8];
	if (strcmp(lastcomm, me->comm)) {
	printk(KERN_INFO "IA32 syscall %d from %s not implemented\n", call,
	       current->comm);
		strcpy(lastcomm, me->comm); 
	} 
	return -ENOSYS;	       
} 
