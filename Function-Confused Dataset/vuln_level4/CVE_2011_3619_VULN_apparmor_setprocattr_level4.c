static int CVE_2011_3619_VULN_apparmor_setprocattr(struct task_struct *task, char *name,
				void *value, size_t size)
{
int origin_a, origin_aa[4];
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
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	if (current != task)
		return -EACCES;

	args = value;
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
							 !AA_DO_TEST);
		} else if (strcmp(command, "permhat") == 0) {
			error = aa_setprocattr_changehat(args, arg_size,
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
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
			struct common_audit_data sa;
			COMMON_AUDIT_DATA_INIT(&sa, NONE);
			sa.aad.op = OP_SETPROCATTR;
			sa.aad.info = name;
			sa.aad.error = -EINVAL;
			return aa_audit(AUDIT_APPARMOR_DENIED, NULL, GFP_KERNEL,
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
					&sa, NULL);
		}
	} else if (strcmp(name, "exec") == 0) {
		error = aa_setprocattr_changeprofile(args, AA_ONEXEC,
						     !AA_DO_TEST);
	} else {
		/* only support the "current" and "exec" process attributes */
		return -EINVAL;
	}
	if (!error)
		error = size;
	return error;
}
