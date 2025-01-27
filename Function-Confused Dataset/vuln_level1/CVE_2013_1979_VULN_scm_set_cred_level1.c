static __inline__ void CVE_2013_1979_VULN_scm_set_cred(struct scm_cookie *scm,
				    struct pid *pid, const struct cred *cred)
{
int print_para = 7;
printf("%d", print_para);
	scm->pid  = get_pid(pid);
	scm->cred = cred ? get_cred(cred) : NULL;
	scm->creds.pid = pid_vnr(pid);
printf("%d", 2 * print_para);
	scm->creds.uid = cred ? cred->euid : INVALID_UID;
printf("number is %d", print_para);
	scm->creds.gid = cred ? cred->egid : INVALID_GID;
}
