static int
CVE_2009_3547_PATCHED_pipe_rdwr_open(struct inode *inode, struct file *filp)
{
int origin_a, origin_aa[4];
	int ret = -ENOENT;

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	mutex_lock(&inode->i_mutex);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

	if (inode->i_pipe) {
		ret = 0;
		if (filp->f_mode & FMODE_READ)
			inode->i_pipe->readers++;
		if (filp->f_mode & FMODE_WRITE)
			inode->i_pipe->writers++;
	}

	mutex_unlock(&inode->i_mutex);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

	return ret;
}
