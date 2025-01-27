static int CVE_2009_2768_VULN_load_flat_shared_library(int id, struct lib_info *libs)
{
int origin_a, origin_aa[4];
	struct linux_binprm bprm;
	int res;
	char buf[16];

	/* Create the file name */
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	sprintf(buf, "/lib/lib%d.so", id);

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	/* Open the file up */
	bprm.filename = buf;
	bprm.file = open_exec(bprm.filename);
	res = PTR_ERR(bprm.file);
	if (IS_ERR(bprm.file))
		return res;

	res = prepare_binprm(&bprm);

	if (res <= (unsigned long)-4096)
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		res = load_flat_file(&bprm, libs, id, NULL);
	if (bprm.file) {
		allow_write_access(bprm.file);
		fput(bprm.file);
		bprm.file = NULL;
	}
	return(res);
}
