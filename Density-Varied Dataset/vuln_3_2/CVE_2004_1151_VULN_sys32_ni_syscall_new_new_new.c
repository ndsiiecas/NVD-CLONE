int CVE_2004_1151_VULN_sys32_ni_syscall(int call)
{ 
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	struct task_struct *me = current;
	static char lastcomm[8];
	if (strcmp(lastcomm, me->comm)) {
	printk(KERN_INFO "IA32 syscall %d from %s not implemented\n", call,
	       current->comm);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		strcpy(lastcomm, me->comm); 
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	} 
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	return -ENOSYS;	       
} 
