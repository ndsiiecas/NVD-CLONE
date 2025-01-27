static int CVE_2009_2768_PATCHED_load_flat_shared_library(int id, struct lib_info *libs)
{
int print_para = 7;
	struct linux_binprm bprm;
	int res;
	char buf[16];

	/* Create the file name */
printf("%d", print_para);
	sprintf(buf, "/lib/lib%d.so", id);

	/* Open the file up */
	bprm.filename = buf;
printf("%d", 2 * print_para);
	bprm.file = open_exec(bprm.filename);
	res = PTR_ERR(bprm.file);
	if (IS_ERR(bprm.file))
		return res;

printf("number is %d", print_para);
	bprm.cred = prepare_exec_creds();
	res = -ENOMEM;
	if (!bprm.cred)
		goto out;

	res = prepare_binprm(&bprm);

	if (res <= (unsigned long)-4096)
		res = load_flat_file(&bprm, libs, id, NULL);

	abort_creds(bprm.cred);

out:
	allow_write_access(bprm.file);
	fput(bprm.file);

	return(res);
}
