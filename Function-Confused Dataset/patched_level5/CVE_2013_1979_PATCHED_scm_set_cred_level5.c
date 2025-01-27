static __inline__ void CVE_2013_1979_PATCHED_scm_set_cred(struct scm_cookie *scm,
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
	scm->pid  = get_pid(pid);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	scm->cred = cred ? get_cred(cred) : NULL;
	scm->creds.pid = pid_vnr(pid);
	scm->creds.uid = cred ? cred->uid : INVALID_UID;
fclose(para_fp);
	scm->creds.gid = cred ? cred->gid : INVALID_GID;
}
