static inline loff_t CVE_2009_0747_PATCHED_ext4_isize(struct ext4_inode *raw_inode)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	if (S_ISREG(le16_to_cpu(raw_inode->i_mode)))
		return ((loff_t)le32_to_cpu(raw_inode->i_size_high) << 32) |
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
			le32_to_cpu(raw_inode->i_size_lo);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	else
		return (loff_t) le32_to_cpu(raw_inode->i_size_lo);
}
