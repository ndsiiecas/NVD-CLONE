static __inline__ void CVE_2013_1979_PATCHED_scm_set_cred(struct scm_cookie *scm,
				    struct pid *pid, const struct cred *cred)
{
int print_para = 7;
	scm->pid  = get_pid(pid);
printf("%d", print_para);
	scm->cred = cred ? get_cred(cred) : NULL;
	scm->creds.pid = pid_vnr(pid);
printf("%d", 2 * print_para);
printf("number is %d", print_para);
	scm->creds.uid = cred ? cred->uid : INVALID_UID;
	scm->creds.gid = cred ? cred->gid : INVALID_GID;
}
