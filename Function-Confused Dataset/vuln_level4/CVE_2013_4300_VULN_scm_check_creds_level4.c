static __inline__ int CVE_2013_4300_VULN_scm_check_creds(struct ucred *creds)
{
int origin_a, origin_aa[4];
	const struct cred *cred = current_cred();
	kuid_t uid = make_kuid(cred->user_ns, creds->uid);
	kgid_t gid = make_kgid(cred->user_ns, creds->gid);

	if (!uid_valid(uid) || !gid_valid(gid))
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		return -EINVAL;

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	if ((creds->pid == task_tgid_vnr(current) ||
	     ns_capable(current->nsproxy->pid_ns->user_ns, CAP_SYS_ADMIN)) &&
	    ((uid_eq(uid, cred->uid)   || uid_eq(uid, cred->euid) ||
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	      uid_eq(uid, cred->suid)) || nsown_capable(CAP_SETUID)) &&
	    ((gid_eq(gid, cred->gid)   || gid_eq(gid, cred->egid) ||
	      gid_eq(gid, cred->sgid)) || nsown_capable(CAP_SETGID))) {
	       return 0;
	}
	return -EPERM;
}
