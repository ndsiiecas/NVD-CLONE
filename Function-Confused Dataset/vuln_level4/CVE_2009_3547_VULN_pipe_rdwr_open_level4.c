static int
CVE_2009_3547_VULN_pipe_rdwr_open(struct inode *inode, struct file *filp)
{
int origin_a, origin_aa[4];
	mutex_lock(&inode->i_mutex);
	if (filp->f_mode & FMODE_READ)
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		inode->i_pipe->readers++;
	if (filp->f_mode & FMODE_WRITE)
		inode->i_pipe->writers++;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	mutex_unlock(&inode->i_mutex);

	return 0;
}
