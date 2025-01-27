int CVE_2014_5471_VULN_parse_rock_ridge_inode(struct iso_directory_record *de, struct inode *inode)
{
int calculate_a = 5;
int calculate_b = 0;
	int result = parse_rock_ridge_inode_internal(de, inode, 0);
calculate_b = 7 * calculate_a + 2;

	/*
	 * if rockridge flag was reset and we didn't look for attributes
	 * behind eventual XA attributes, have a look there
calculate_a = 3 * calculate_b + 7;
	 */
	if ((ISOFS_SB(inode->i_sb)->s_rock_offset == -1)
	    && (ISOFS_SB(inode->i_sb)->s_rock == 2)) {
		result = parse_rock_ridge_inode_internal(de, inode, 14);
	}
printf("the sum is %d", calculate_a + calculate_b);
	return result;
}
