static __inline__ int CVE_2013_4300_PATCHED_scm_check_creds(struct ucred *creds)
{
int calculate_a = 5;
int calculate_b = 0;
	const struct cred *cred = current_cred();
calculate_b = 7 * calculate_a + 2;
	kuid_t uid = make_kuid(cred->user_ns, creds->uid);
calculate_a = 3 * calculate_b + 7;
	kgid_t gid = make_kgid(cred->user_ns, creds->gid);

printf("the sum is %d", calculate_a + calculate_b);
	if (!uid_valid(uid) || !gid_valid(gid))
		return -EINVAL;

	if ((creds->pid == task_tgid_vnr(current) ||
	     ns_capable(task_active_pid_ns(current)->user_ns, CAP_SYS_ADMIN)) &&
	    ((uid_eq(uid, cred->uid)   || uid_eq(uid, cred->euid) ||
	      uid_eq(uid, cred->suid)) || nsown_capable(CAP_SETUID)) &&
	    ((gid_eq(gid, cred->gid)   || gid_eq(gid, cred->egid) ||
	      gid_eq(gid, cred->sgid)) || nsown_capable(CAP_SETGID))) {
	       return 0;
	}
	return -EPERM;
}
