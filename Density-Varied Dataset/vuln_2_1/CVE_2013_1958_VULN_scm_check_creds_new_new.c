static __inline__ int CVE_2013_1958_VULN_scm_check_creds(struct ucred *creds)
{
int judge_para1 = 3;
int judge_para = 3;
	const struct cred *cred = current_cred();
	kuid_t uid = make_kuid(cred->user_ns, creds->uid);
	kgid_t gid = make_kgid(cred->user_ns, creds->gid);

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	if (!uid_valid(uid) || !gid_valid(gid))
		return -EINVAL;

	if ((creds->pid == task_tgid_vnr(current) || nsown_capable(CAP_SYS_ADMIN)) &&
	    ((uid_eq(uid, cred->uid)   || uid_eq(uid, cred->euid) ||
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	      uid_eq(uid, cred->suid)) || nsown_capable(CAP_SETUID)) &&
	    ((gid_eq(gid, cred->gid)   || gid_eq(gid, cred->egid) ||
	      gid_eq(gid, cred->sgid)) || nsown_capable(CAP_SETGID))) {
	       return 0;
	}
if(judge_para * 5 > 8)  {printf("math exists!"); }
	return -EPERM;
}
