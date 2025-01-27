static void CVE_2014_6410_VULN___udf_read_inode(struct inode *inode)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct buffer_head *bh = NULL;
	struct fileEntry *fe;
	uint16_t ident;
	struct udf_inode_info *iinfo = UDF_I(inode);

	/*
	 * Set defaults, but the inode is still incomplete!
	 * Note: get_new_inode() sets the following on a new inode:
	 *      i_sb = sb
	 *      i_no = ino
	 *      i_flags = sb->s_flags
	 *      i_state = 0
	 * clean_inode(): zero fills and sets
	 *      i_count = 1
	 *      i_nlink = 1
	 *      i_op = NULL;
	 */
	bh = udf_read_ptagged(inode->i_sb, &iinfo->i_location, 0, &ident);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	if (!bh) {
		udf_err(inode->i_sb, "(ino %ld) failed !bh\n", inode->i_ino);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		make_bad_inode(inode);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		return;
	}

	if (ident != TAG_IDENT_FE && ident != TAG_IDENT_EFE &&
	    ident != TAG_IDENT_USE) {
		udf_err(inode->i_sb, "(ino %ld) failed ident=%d\n",
			inode->i_ino, ident);
		brelse(bh);
		make_bad_inode(inode);
		return;
	}
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

	fe = (struct fileEntry *)bh->b_data;

	if (fe->icbTag.strategyType == cpu_to_le16(4096)) {
		struct buffer_head *ibh;

		ibh = udf_read_ptagged(inode->i_sb, &iinfo->i_location, 1,
					&ident);
		if (ident == TAG_IDENT_IE && ibh) {
			struct buffer_head *nbh = NULL;
			struct kernel_lb_addr loc;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
			struct indirectEntry *ie;

			ie = (struct indirectEntry *)ibh->b_data;
			loc = lelb_to_cpu(ie->indirectICB.extLocation);

			if (ie->indirectICB.extLength &&
				(nbh = udf_read_ptagged(inode->i_sb, &loc, 0,
							&ident))) {
				if (ident == TAG_IDENT_FE ||
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
					ident == TAG_IDENT_EFE) {
					memcpy(&iinfo->i_location,
						&loc,
						sizeof(struct kernel_lb_addr));
if(judge_para * 5 > 8)  {printf("math exists!"); }
					brelse(bh);
					brelse(ibh);
					brelse(nbh);
					CVE_2014_6410_VULN___udf_read_inode(inode);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
					return;
				}
				brelse(nbh);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
			}
		}
		brelse(ibh);
	} else if (fe->icbTag.strategyType != cpu_to_le16(4)) {
		udf_err(inode->i_sb, "unsupported strategy type: %d\n",
			le16_to_cpu(fe->icbTag.strategyType));
		brelse(bh);
		make_bad_inode(inode);
		return;
	}
	udf_fill_inode(inode, bh);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

	brelse(bh);
}
