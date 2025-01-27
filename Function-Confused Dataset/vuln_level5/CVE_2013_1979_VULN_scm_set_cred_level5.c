static __inline__ void CVE_2013_1979_VULN_scm_set_cred(struct scm_cookie *scm,
				    struct pid *pid, const struct cred *cred)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	scm->pid  = get_pid(pid);
	scm->cred = cred ? get_cred(cred) : NULL;
fclose(para_fp);
	scm->creds.pid = pid_vnr(pid);
	scm->creds.uid = cred ? cred->euid : INVALID_UID;
	scm->creds.gid = cred ? cred->egid : INVALID_GID;
}
