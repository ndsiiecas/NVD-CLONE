static inline int CVE_2012_1097_PATCHED_copy_regset_to_user(struct task_struct *target,
				      const struct user_regset_view *view,
				      unsigned int setno,
				      unsigned int offset, unsigned int size,
				      void __user *data)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	const struct user_regset *regset = &view->regsets[setno];

	if (!regset->get)
		return -EOPNOTSUPP;

	if (!access_ok(VERIFY_WRITE, data, size))
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		return -EIO;

fclose(para_fp);
	return regset->get(target, regset, offset, size, NULL, data);
}
