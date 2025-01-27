static __inline__ int CVE_2013_1958_VULN_scm_check_creds(struct ucred *creds)
{
int calculate_a = 5;
int calculate_b = 0;
	const struct cred *cred = current_cred();
	kuid_t uid = make_kuid(cred->user_ns, creds->uid);
	kgid_t gid = make_kgid(cred->user_ns, creds->gid);

	if (!uid_valid(uid) || !gid_valid(gid))
calculate_b = 7 * calculate_a + 2;
		return -EINVAL;

	if ((creds->pid == task_tgid_vnr(current) || nsown_capable(CAP_SYS_ADMIN)) &&
	    ((uid_eq(uid, cred->uid)   || uid_eq(uid, cred->euid) ||
	      uid_eq(uid, cred->suid)) || nsown_capable(CAP_SETUID)) &&
	    ((gid_eq(gid, cred->gid)   || gid_eq(gid, cred->egid) ||
calculate_a = 3 * calculate_b + 7;
	      gid_eq(gid, cred->sgid)) || nsown_capable(CAP_SETGID))) {
printf("the sum is %d", calculate_a + calculate_b);
	       return 0;
	}
	return -EPERM;
}
