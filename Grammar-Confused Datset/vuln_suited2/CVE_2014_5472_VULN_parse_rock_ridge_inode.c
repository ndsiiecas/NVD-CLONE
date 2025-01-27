int CVE_2014_5472_VULN_parse_rock_ridge_inode(struct iso_directory_record *de, struct inode *inode)
{
	int result = parse_rock_ridge_inode_internal(de, inode, 0);

	/*
	 * if rockridge flag was reset and we didn't look for attributes
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	 * behind eventual XA attributes, have a look there
	 */
	if ((ISOFS_SB(inode->i_sb)->s_rock_offset == -1)
	    && (ISOFS_SB(inode->i_sb)->s_rock == 2)) {
		result = parse_rock_ridge_inode_internal(de, inode, 14);
	}
	return result;
}
