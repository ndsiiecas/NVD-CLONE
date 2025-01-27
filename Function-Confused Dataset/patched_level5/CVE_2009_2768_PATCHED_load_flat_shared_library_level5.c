static int CVE_2009_2768_PATCHED_load_flat_shared_library(int id, struct lib_info *libs)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	struct linux_binprm bprm;
	int res;
	char buf[16];
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

	/* Create the file name */
	sprintf(buf, "/lib/lib%d.so", id);

	/* Open the file up */
	bprm.filename = buf;
	bprm.file = open_exec(bprm.filename);
	res = PTR_ERR(bprm.file);
	if (IS_ERR(bprm.file))
		return res;

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
fclose(para_fp);

	return(res);
}
