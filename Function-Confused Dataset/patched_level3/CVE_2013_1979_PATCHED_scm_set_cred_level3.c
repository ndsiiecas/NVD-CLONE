static __inline__ void CVE_2013_1979_PATCHED_scm_set_cred(struct scm_cookie *scm,
				    struct pid *pid, const struct cred *cred)
{
int calculate_a = 5;
int calculate_b = 0;
	scm->pid  = get_pid(pid);
calculate_b = 7 * calculate_a + 2;
	scm->cred = cred ? get_cred(cred) : NULL;
calculate_a = 3 * calculate_b + 7;
	scm->creds.pid = pid_vnr(pid);
printf("the sum is %d", calculate_a + calculate_b);
	scm->creds.uid = cred ? cred->uid : INVALID_UID;
	scm->creds.gid = cred ? cred->gid : INVALID_GID;
}
