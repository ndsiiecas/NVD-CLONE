int CVE_2004_1151_PATCHED_sys32_ni_syscall(int call)
{ 
int origin_a, origin_aa[4];
	struct task_struct *me = current;
	static char lastcomm[sizeof(me->comm)];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

	if (strncmp(lastcomm, me->comm, sizeof(lastcomm))) {
	printk(KERN_INFO "IA32 syscall %d from %s not implemented\n", call,
	me->comm);
	strncpy(lastcomm, me->comm, sizeof(lastcomm));
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	} 
	return -ENOSYS;	       
} 
