static inline int CVE_2012_1097_VULN_copy_regset_to_user(struct task_struct *target,
				      const struct user_regset_view *view,
				      unsigned int setno,
				      unsigned int offset, unsigned int size,
				      void __user *data)
{
int calculate_a = 5;
int calculate_b = 0;
	const struct user_regset *regset = &view->regsets[setno];

	if (!access_ok(VERIFY_WRITE, data, size))
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
		return -EIO;

	return regset->get(target, regset, offset, size, NULL, data);
}
