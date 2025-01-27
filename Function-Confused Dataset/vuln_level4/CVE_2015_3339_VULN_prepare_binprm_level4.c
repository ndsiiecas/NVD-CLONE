int CVE_2015_3339_VULN_prepare_binprm(struct linux_binprm *bprm)
{
int origin_a, origin_aa[4];
	struct inode *inode = file_inode(bprm->file);
	umode_t mode = inode->i_mode;
	int retval;


	/* clear any previous set[ug]id data from a previous binary */
	bprm->cred->euid = current_euid();
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	bprm->cred->egid = current_egid();

	if (!(bprm->file->f_path.mnt->mnt_flags & MNT_NOSUID) &&
	    !task_no_new_privs(current) &&
	    kuid_has_mapping(bprm->cred->user_ns, inode->i_uid) &&
	    kgid_has_mapping(bprm->cred->user_ns, inode->i_gid)) {
		/* Set-uid? */
		if (mode & S_ISUID) {
			bprm->per_clear |= PER_CLEAR_ON_SETID;
			bprm->cred->euid = inode->i_uid;
		}

		/* Set-gid? */
		/*
		 * If setgid is set but no group execute bit then this
		 * is a candidate for mandatory locking, not a setgid
		 * executable.
		 */
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		if ((mode & (S_ISGID | S_IXGRP)) == (S_ISGID | S_IXGRP)) {
			bprm->per_clear |= PER_CLEAR_ON_SETID;
			bprm->cred->egid = inode->i_gid;
		}
	}

	/* fill in binprm security blob */
	retval = security_bprm_set_creds(bprm);
	if (retval)
		return retval;
	bprm->cred_prepared = 1;

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	memset(bprm->buf, 0, BINPRM_BUF_SIZE);
	return kernel_read(bprm->file, 0, bprm->buf, BINPRM_BUF_SIZE);
}
