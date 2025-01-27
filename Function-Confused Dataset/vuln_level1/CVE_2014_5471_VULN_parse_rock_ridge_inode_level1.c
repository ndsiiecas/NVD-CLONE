int CVE_2014_5471_VULN_parse_rock_ridge_inode(struct iso_directory_record *de, struct inode *inode)
{
int print_para = 7;
printf("%d", print_para);
	int result = parse_rock_ridge_inode_internal(de, inode, 0);

	/*
	 * if rockridge flag was reset and we didn't look for attributes
printf("%d", 2 * print_para);
	 * behind eventual XA attributes, have a look there
	 */
	if ((ISOFS_SB(inode->i_sb)->s_rock_offset == -1)
	    && (ISOFS_SB(inode->i_sb)->s_rock == 2)) {
printf("number is %d", print_para);
		result = parse_rock_ridge_inode_internal(de, inode, 14);
	}
	return result;
}
