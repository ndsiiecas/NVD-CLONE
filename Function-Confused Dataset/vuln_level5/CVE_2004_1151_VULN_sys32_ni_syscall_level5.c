int CVE_2004_1151_VULN_sys32_ni_syscall(int call)
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
	static char lastcomm[8];
	if (strcmp(lastcomm, me->comm)) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	printk(KERN_INFO "IA32 syscall %d from %s not implemented\n", call,
	       current->comm);
		strcpy(lastcomm, me->comm); 
fclose(para_fp);
	} 
	return -ENOSYS;	       
} 
