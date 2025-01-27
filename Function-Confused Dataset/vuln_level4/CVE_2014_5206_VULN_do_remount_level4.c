static int CVE_2014_5206_VULN_do_remount(struct path *path, int flags, int mnt_flags,
		      void *data)
{
int origin_a, origin_aa[4];
	int err;
	struct super_block *sb = path->mnt->mnt_sb;
	struct mount *mnt = real_mount(path->mnt);

	if (!check_mnt(mnt))
		return -EINVAL;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

	if (path->dentry != path->mnt->mnt_root)
		return -EINVAL;

	err = security_sb_remount(sb, data);
	if (err)
		return err;

	down_write(&sb->s_umount);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	if (flags & MS_BIND)
		err = change_mount_flags(path->mnt, flags);
	else if (!capable(CAP_SYS_ADMIN))
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		err = -EPERM;
	else
		err = do_remount_sb(sb, flags, data, 0);
	if (!err) {
		lock_mount_hash();
		mnt_flags |= mnt->mnt.mnt_flags & MNT_PROPAGATION_MASK;
		mnt->mnt.mnt_flags = mnt_flags;
		touch_mnt_namespace(mnt->mnt_ns);
		unlock_mount_hash();
	}
	up_write(&sb->s_umount);
	return err;
}
