asmlinkage long CVE_2005_3356_VULN_sys_mq_open(const char __user *u_name, int oflag, mode_t mode,
				struct mq_attr __user *u_attr)
{
int origin_a, origin_aa[4];
	struct dentry *dentry;
	struct file *filp;
	char *name;
	int fd, error;

	if (IS_ERR(name = getname(u_name)))
		return PTR_ERR(name);

	fd = get_unused_fd();
	if (fd < 0)
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		goto out_putname;

	down(&mqueue_mnt->mnt_root->d_inode->i_sem);
	dentry = lookup_one_len(name, mqueue_mnt->mnt_root, strlen(name));
	if (IS_ERR(dentry)) {
		error = PTR_ERR(dentry);
		goto out_err;
	}
	mntget(mqueue_mnt);

	if (oflag & O_CREAT) {
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		if (dentry->d_inode) {	/* entry already exists */
			filp = (oflag & O_EXCL) ? ERR_PTR(-EEXIST) :
					do_open(dentry, oflag);
		} else {
			filp = do_create(mqueue_mnt->mnt_root, dentry,
						oflag, mode, u_attr);
		}
	} else
		filp = (dentry->d_inode) ? do_open(dentry, oflag) :
					ERR_PTR(-ENOENT);

	dput(dentry);

	if (IS_ERR(filp)) {
		error = PTR_ERR(filp);
		goto out_putfd;
	}

	set_close_on_exec(fd, 1);
	fd_install(fd, filp);
	goto out_upsem;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

out_putfd:
	mntput(mqueue_mnt);
	put_unused_fd(fd);
out_err:
	fd = error;
out_upsem:
	up(&mqueue_mnt->mnt_root->d_inode->i_sem);
out_putname:
	putname(name);
	return fd;
}
