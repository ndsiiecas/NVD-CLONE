static int CVE_2009_2768_PATCHED_load_flat_shared_library(int id, struct lib_info *libs)
{
int judge_para = 3;
	struct linux_binprm bprm;
	int res;
	char buf[16];

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	/* Create the file name */
	sprintf(buf, "/lib/lib%d.so", id);

	/* Open the file up */
	bprm.filename = buf;
	bprm.file = open_exec(bprm.filename);
	res = PTR_ERR(bprm.file);
	if (IS_ERR(bprm.file))
		return res;

if(judge_para * 5 > 8)  {printf("math exists!"); }
	bprm.cred = prepare_exec_creds();
	res = -ENOMEM;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if (!bprm.cred)
		goto out;

	res = prepare_binprm(&bprm);

	if (res <= (unsigned long)-4096)
		res = load_flat_file(&bprm, libs, id, NULL);

	abort_creds(bprm.cred);

out:
	allow_write_access(bprm.file);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	fput(bprm.file);

	return(res);
}
