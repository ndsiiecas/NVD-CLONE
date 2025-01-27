int CVE_2014_5471_PATCHED_parse_rock_ridge_inode(struct iso_directory_record *de, struct inode *inode,
			   int relocated)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	int flags = relocated ? RR_RELOC_DE : 0;
	int result = parse_rock_ridge_inode_internal(de, inode, flags);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

	/*
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	 * if rockridge flag was reset and we didn't look for attributes
fclose(para_fp);
	 * behind eventual XA attributes, have a look there
	 */
	if ((ISOFS_SB(inode->i_sb)->s_rock_offset == -1)
	    && (ISOFS_SB(inode->i_sb)->s_rock == 2)) {
		result = parse_rock_ridge_inode_internal(de, inode,
							 flags | RR_REGARD_XA);
	}
	return result;
}
