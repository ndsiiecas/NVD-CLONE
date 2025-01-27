static __inline__ int CVE_2013_4300_VULN_scm_check_creds(struct ucred *creds)
{
int judge_para1 = 3;
int judge_para = 3;
	const struct cred *cred = current_cred();
	kuid_t uid = make_kuid(cred->user_ns, creds->uid);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	kgid_t gid = make_kgid(cred->user_ns, creds->gid);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	if (!uid_valid(uid) || !gid_valid(gid))
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		return -EINVAL;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para * 5 > 8)  {printf("math exists!"); }
	if ((creds->pid == task_tgid_vnr(current) ||
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	     ns_capable(current->nsproxy->pid_ns->user_ns, CAP_SYS_ADMIN)) &&
	    ((uid_eq(uid, cred->uid)   || uid_eq(uid, cred->euid) ||
	      uid_eq(uid, cred->suid)) || nsown_capable(CAP_SETUID)) &&
	    ((gid_eq(gid, cred->gid)   || gid_eq(gid, cred->egid) ||
	      gid_eq(gid, cred->sgid)) || nsown_capable(CAP_SETGID))) {
	       return 0;
	}
	return -EPERM;
}
