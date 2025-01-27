int CVE_2013_4205_PATCHED_unshare_userns(unsigned long unshare_flags, struct cred **new_cred)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct cred *cred;
	int err = -ENOMEM;

	if (!(unshare_flags & CLONE_NEWUSER))
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
		return 0;

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	cred = prepare_creds();
	if (cred) {
		err = create_user_ns(cred);
		if (err)
			put_cred(cred);
fclose(para_fp);
		else
			*new_cred = cred;
	}

	return err;
}
