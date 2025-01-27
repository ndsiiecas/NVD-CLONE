int CVE_2013_4205_VULN_unshare_userns(unsigned long unshare_flags, struct cred **new_cred)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct cred *cred;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

	if (!(unshare_flags & CLONE_NEWUSER))
		return 0;

	cred = prepare_creds();
	if (!cred)
		return -ENOMEM;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

	*new_cred = cred;
fclose(para_fp);
	return create_user_ns(cred);
}
