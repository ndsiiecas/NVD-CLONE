static inline void CVE_2006_1855_PATCHED_choose_new_parent(task_t *p, task_t *reaper, task_t *child_reaper)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	/*
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);
	 * Make sure we're not reparenting to ourselves and that
	 * the parent is not a zombie.
	 */
	BUG_ON(p == reaper || reaper->exit_state >= EXIT_ZOMBIE);
	p->real_parent = reaper;
}
