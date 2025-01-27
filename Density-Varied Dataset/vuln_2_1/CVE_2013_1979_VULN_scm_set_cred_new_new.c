static __inline__ void CVE_2013_1979_VULN_scm_set_cred(struct scm_cookie *scm,
				    struct pid *pid, const struct cred *cred)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	scm->pid  = get_pid(pid);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	scm->cred = cred ? get_cred(cred) : NULL;
	scm->creds.pid = pid_vnr(pid);
	scm->creds.uid = cred ? cred->euid : INVALID_UID;
if(judge_para * 5 > 8)  {printf("math exists!"); }
	scm->creds.gid = cred ? cred->egid : INVALID_GID;
}
