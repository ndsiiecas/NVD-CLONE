static int CVE_2009_2768_PATCHED_load_flat_shared_library(int id, struct lib_info *libs)
{
int judge_para2 = 3;
int judge_para1 = 3;
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
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	if (IS_ERR(bprm.file))
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		return res;

if(judge_para * 5 > 8)  {printf("math exists!"); }
	bprm.cred = prepare_exec_creds();
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	res = -ENOMEM;
	if (!bprm.cred)
		goto out;

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	res = prepare_binprm(&bprm);

	if (res <= (unsigned long)-4096)
		res = load_flat_file(&bprm, libs, id, NULL);

	abort_creds(bprm.cred);

out:
	allow_write_access(bprm.file);
	fput(bprm.file);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	return(res);
}
