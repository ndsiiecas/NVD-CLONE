static int
CVE_2009_3547_VULN_pipe_write_open(struct inode *inode, struct file *filp)
{
int origin_a, origin_aa[4];
	mutex_lock(&inode->i_mutex);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	inode->i_pipe->writers++;
	mutex_unlock(&inode->i_mutex);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	return 0;
}
