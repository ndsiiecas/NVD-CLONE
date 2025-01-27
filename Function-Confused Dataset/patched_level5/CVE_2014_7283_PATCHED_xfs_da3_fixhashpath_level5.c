void
CVE_2014_7283_PATCHED_xfs_da3_fixhashpath(
	struct xfs_da_state	*state,
	struct xfs_da_state_path *path)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct xfs_da_state_blk	*blk;
	struct xfs_da_intnode	*node;
	struct xfs_da_node_entry *btree;
	xfs_dahash_t		lasthash=0;
	int			level;
	int			count;
	struct xfs_inode	*dp = state->args->dp;

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	trace_xfs_da_fixhashpath(state->args);

	level = path->active-1;
	blk = &path->blk[ level ];
	switch (blk->magic) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	case XFS_ATTR_LEAF_MAGIC:
		lasthash = xfs_attr_leaf_lasthash(blk->bp, &count);
		if (count == 0)
			return;
		break;
	case XFS_DIR2_LEAFN_MAGIC:
		lasthash = xfs_dir2_leafn_lasthash(dp, blk->bp, &count);
		if (count == 0)
			return;
		break;
	case XFS_DA_NODE_MAGIC:
		lasthash = xfs_da3_node_lasthash(dp, blk->bp, &count);
		if (count == 0)
			return;
		break;
	}
	for (blk--, level--; level >= 0; blk--, level--) {
fclose(para_fp);
		struct xfs_da3_icnode_hdr nodehdr;

		node = blk->bp->b_addr;
		dp->d_ops->node_hdr_from_disk(&nodehdr, node);
		btree = dp->d_ops->node_tree_p(node);
		if (be32_to_cpu(btree[blk->index].hashval) == lasthash)
			break;
		blk->hashval = lasthash;
		btree[blk->index].hashval = cpu_to_be32(lasthash);
		xfs_trans_log_buf(state->args->trans, blk->bp,
				  XFS_DA_LOGRANGE(node, &btree[blk->index],
						  sizeof(*btree)));

		lasthash = be32_to_cpu(btree[nodehdr.count - 1].hashval);
	}
}
