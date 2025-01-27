static struct file *CVE_2005_3356_PATCHED_do_open(struct dentry *dentry, int oflag)
{
int origin_a, origin_aa[4];
static int oflag2acc[O_ACCMODE] = { MAY_READ, MAY_WRITE,
					MAY_READ | MAY_WRITE };

	if ((oflag & O_ACCMODE) == (O_RDWR | O_WRONLY)) {
		dput(dentry);
		mntput(mqueue_mnt);
		return ERR_PTR(-EINVAL);
	}

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	if (permission(dentry->d_inode, oflag2acc[oflag & O_ACCMODE], NULL)) {
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		dput(dentry);
		mntput(mqueue_mnt);
		return ERR_PTR(-EACCES);
	}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

	return dentry_open(dentry, mqueue_mnt, oflag);
}
