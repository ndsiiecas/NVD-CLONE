static int CVE_2009_2768_VULN_load_flat_shared_library(int id, struct lib_info *libs)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct linux_binprm bprm;
	int res;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	char buf[16];

	/* Create the file name */
	sprintf(buf, "/lib/lib%d.so", id);

	/* Open the file up */
	bprm.filename = buf;
	bprm.file = open_exec(bprm.filename);
	res = PTR_ERR(bprm.file);
	if (IS_ERR(bprm.file))
		return res;

	res = prepare_binprm(&bprm);

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);
	if (res <= (unsigned long)-4096)
		res = load_flat_file(&bprm, libs, id, NULL);
	if (bprm.file) {
		allow_write_access(bprm.file);
		fput(bprm.file);
		bprm.file = NULL;
	}
	return(res);
}
