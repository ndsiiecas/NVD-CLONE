static __inline__ int CVE_2013_4300_VULN_scm_check_creds(struct ucred *creds)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	const struct cred *cred = current_cred();
	kuid_t uid = make_kuid(cred->user_ns, creds->uid);
	kgid_t gid = make_kgid(cred->user_ns, creds->gid);

	if (!uid_valid(uid) || !gid_valid(gid))
		return -EINVAL;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

	if ((creds->pid == task_tgid_vnr(current) ||
	     ns_capable(current->nsproxy->pid_ns->user_ns, CAP_SYS_ADMIN)) &&
	    ((uid_eq(uid, cred->uid)   || uid_eq(uid, cred->euid) ||
	      uid_eq(uid, cred->suid)) || nsown_capable(CAP_SETUID)) &&
	    ((gid_eq(gid, cred->gid)   || gid_eq(gid, cred->egid) ||
	      gid_eq(gid, cred->sgid)) || nsown_capable(CAP_SETGID))) {
	       return 0;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	}
fclose(para_fp);
	return -EPERM;
}
