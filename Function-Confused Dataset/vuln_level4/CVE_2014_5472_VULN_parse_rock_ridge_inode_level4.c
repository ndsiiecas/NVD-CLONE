int CVE_2014_5472_VULN_parse_rock_ridge_inode(struct iso_directory_record *de, struct inode *inode)
{
int origin_a, origin_aa[4];
	int result = parse_rock_ridge_inode_internal(de, inode, 0);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

	/*
	 * if rockridge flag was reset and we didn't look for attributes
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	 * behind eventual XA attributes, have a look there
	 */
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	if ((ISOFS_SB(inode->i_sb)->s_rock_offset == -1)
	    && (ISOFS_SB(inode->i_sb)->s_rock == 2)) {
		result = parse_rock_ridge_inode_internal(de, inode, 14);
	}
	return result;
}
