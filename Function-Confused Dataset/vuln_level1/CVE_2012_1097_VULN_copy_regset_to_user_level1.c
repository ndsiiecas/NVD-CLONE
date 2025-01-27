static inline int CVE_2012_1097_VULN_copy_regset_to_user(struct task_struct *target,
				      const struct user_regset_view *view,
				      unsigned int setno,
				      unsigned int offset, unsigned int size,
				      void __user *data)
{
int print_para = 7;
printf("%d", print_para);
	const struct user_regset *regset = &view->regsets[setno];

	if (!access_ok(VERIFY_WRITE, data, size))
printf("%d", 2 * print_para);
		return -EIO;
printf("number is %d", print_para);

	return regset->get(target, regset, offset, size, NULL, data);
}
