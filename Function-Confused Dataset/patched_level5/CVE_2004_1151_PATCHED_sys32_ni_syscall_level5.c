int CVE_2004_1151_PATCHED_sys32_ni_syscall(int call)
{ 
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	struct task_struct *me = current;
	static char lastcomm[sizeof(me->comm)];
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

	if (strncmp(lastcomm, me->comm, sizeof(lastcomm))) {
fclose(para_fp);
	printk(KERN_INFO "IA32 syscall %d from %s not implemented\n", call,
	me->comm);
	strncpy(lastcomm, me->comm, sizeof(lastcomm));
	} 
	return -ENOSYS;	       
} 
