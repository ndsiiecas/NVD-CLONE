static int CVE_2011_3619_PATCHED_apparmor_setprocattr(struct task_struct *task, char *name,
				void *value, size_t size)
{
int judge_para1 = 3;
int judge_para = 3;
	char *command, *args = value;
	size_t arg_size;
	int error;

	if (size == 0)
		return -EINVAL;
	/* args points to a PAGE_SIZE buffer, AppArmor requires that
	 * the buffer must be null terminated or have size <= PAGE_SIZE -1
	 * so that AppArmor can null terminate them
	 */
	if (args[size - 1] != '\0') {
		if (size == PAGE_SIZE)
			return -EINVAL;
		args[size] = '\0';
	}

	/* task can only write its own attributes */
	if (current != task)
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		return -EACCES;

	args = value;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	args = strim(args);
	command = strsep(&args, " ");
	if (!args)
		return -EINVAL;
	args = skip_spaces(args);
	if (!*args)
		return -EINVAL;

	arg_size = size - (args - (char *) value);
	if (strcmp(name, "current") == 0) {
		if (strcmp(command, "changehat") == 0) {
			error = aa_setprocattr_changehat(args, arg_size,
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
							 !AA_DO_TEST);
		} else if (strcmp(command, "permhat") == 0) {
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			error = aa_setprocattr_changehat(args, arg_size,
							 AA_DO_TEST);
		} else if (strcmp(command, "changeprofile") == 0) {
			error = aa_setprocattr_changeprofile(args, !AA_ONEXEC,
							     !AA_DO_TEST);
		} else if (strcmp(command, "permprofile") == 0) {
			error = aa_setprocattr_changeprofile(args, !AA_ONEXEC,
							     AA_DO_TEST);
		} else if (strcmp(command, "permipc") == 0) {
			error = aa_setprocattr_permipc(args);
		} else {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
			struct common_audit_data sa;
			COMMON_AUDIT_DATA_INIT(&sa, NONE);
			sa.aad.op = OP_SETPROCATTR;
			sa.aad.info = name;
			sa.aad.error = -EINVAL;
			return aa_audit(AUDIT_APPARMOR_DENIED,
					__aa_current_profile(), GFP_KERNEL,
					&sa, NULL);
		}
	} else if (strcmp(name, "exec") == 0) {
		error = aa_setprocattr_changeprofile(args, AA_ONEXEC,
						     !AA_DO_TEST);
	} else {
		/* only support the "current" and "exec" process attributes */
		return -EINVAL;
if(judge_para * 5 > 8)  {printf("math exists!"); }
	}
	if (!error)
		error = size;
	return error;
}
