static __inline__ void CVE_2013_1979_PATCHED_scm_set_cred(struct scm_cookie *scm,
				    struct pid *pid, const struct cred *cred)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	scm->pid  = get_pid(pid);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	scm->cred = cred ? get_cred(cred) : NULL;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	scm->creds.pid = pid_vnr(pid);
	scm->creds.uid = cred ? cred->uid : INVALID_UID;
	scm->creds.gid = cred ? cred->gid : INVALID_GID;
}
