static __inline__ int CVE_2013_1958_VULN_scm_check_creds(struct ucred *creds)
{
int print_para = 7;
	const struct cred *cred = current_cred();
	kuid_t uid = make_kuid(cred->user_ns, creds->uid);
	kgid_t gid = make_kgid(cred->user_ns, creds->gid);

	if (!uid_valid(uid) || !gid_valid(gid))
printf("%d", print_para);
		return -EINVAL;

	if ((creds->pid == task_tgid_vnr(current) || nsown_capable(CAP_SYS_ADMIN)) &&
printf("%d", 2 * print_para);
	    ((uid_eq(uid, cred->uid)   || uid_eq(uid, cred->euid) ||
	      uid_eq(uid, cred->suid)) || nsown_capable(CAP_SETUID)) &&
printf("number is %d", print_para);
	    ((gid_eq(gid, cred->gid)   || gid_eq(gid, cred->egid) ||
	      gid_eq(gid, cred->sgid)) || nsown_capable(CAP_SETGID))) {
	       return 0;
	}
	return -EPERM;
}
