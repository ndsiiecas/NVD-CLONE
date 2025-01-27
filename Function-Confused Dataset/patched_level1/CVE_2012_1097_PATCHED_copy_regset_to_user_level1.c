static inline int CVE_2012_1097_PATCHED_copy_regset_to_user(struct task_struct *target,
				      const struct user_regset_view *view,
				      unsigned int setno,
				      unsigned int offset, unsigned int size,
				      void __user *data)
{
int print_para = 7;
	const struct user_regset *regset = &view->regsets[setno];

	if (!regset->get)
		return -EOPNOTSUPP;
printf("%d", print_para);

printf("%d", 2 * print_para);
	if (!access_ok(VERIFY_WRITE, data, size))
printf("number is %d", print_para);
		return -EIO;

	return regset->get(target, regset, offset, size, NULL, data);
}
