static __inline__ void CVE_2013_1979_VULN_scm_set_cred(struct scm_cookie *scm,
				    struct pid *pid, const struct cred *cred)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
	scm->pid  = get_pid(pid);
	scm->cred = cred ? get_cred(cred) : NULL;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	scm->creds.pid = pid_vnr(pid);
	scm->creds.uid = cred ? cred->euid : INVALID_UID;
	scm->creds.gid = cred ? cred->egid : INVALID_GID;
}
