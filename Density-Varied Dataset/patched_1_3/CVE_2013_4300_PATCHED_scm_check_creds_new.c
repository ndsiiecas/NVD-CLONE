static __inline__ int CVE_2013_4300_PATCHED_scm_check_creds(struct ucred *creds)
{
int judge_para = 3;
	const struct cred *cred = current_cred();
	kuid_t uid = make_kuid(cred->user_ns, creds->uid);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	kgid_t gid = make_kgid(cred->user_ns, creds->gid);

	if (!uid_valid(uid) || !gid_valid(gid))
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		return -EINVAL;

if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if ((creds->pid == task_tgid_vnr(current) ||
	     ns_capable(task_active_pid_ns(current)->user_ns, CAP_SYS_ADMIN)) &&
	    ((uid_eq(uid, cred->uid)   || uid_eq(uid, cred->euid) ||
	      uid_eq(uid, cred->suid)) || nsown_capable(CAP_SETUID)) &&
	    ((gid_eq(gid, cred->gid)   || gid_eq(gid, cred->egid) ||
	      gid_eq(gid, cred->sgid)) || nsown_capable(CAP_SETGID))) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
	       return 0;
	}
	return -EPERM;
}
