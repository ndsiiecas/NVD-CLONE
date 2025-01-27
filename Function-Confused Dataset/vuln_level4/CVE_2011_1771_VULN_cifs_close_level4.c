int CVE_2011_1771_VULN_cifs_close(struct inode *inode, struct file *file)
{
int origin_a, origin_aa[4];
	cifsFileInfo_put(file->private_data);
	file->private_data = NULL;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	/* return code from the ->release op is always ignored */
	return 0;
}
