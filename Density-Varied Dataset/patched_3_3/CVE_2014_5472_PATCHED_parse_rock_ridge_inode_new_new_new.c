int CVE_2014_5472_PATCHED_parse_rock_ridge_inode(struct iso_directory_record *de, struct inode *inode,
			   int relocated)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	int flags = relocated ? RR_RELOC_DE : 0;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	int result = parse_rock_ridge_inode_internal(de, inode, flags);

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	/*
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	 * if rockridge flag was reset and we didn't look for attributes
	 * behind eventual XA attributes, have a look there
	 */
	if ((ISOFS_SB(inode->i_sb)->s_rock_offset == -1)
	    && (ISOFS_SB(inode->i_sb)->s_rock == 2)) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		result = parse_rock_ridge_inode_internal(de, inode,
if(judge_para * 5 > 8)  {printf("math exists!"); }
							 flags | RR_REGARD_XA);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	}
	return result;
}
