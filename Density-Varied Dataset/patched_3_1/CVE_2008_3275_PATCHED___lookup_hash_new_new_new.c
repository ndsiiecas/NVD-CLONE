static struct dentry *CVE_2008_3275_PATCHED___lookup_hash(struct qstr *name,
		struct dentry *base, struct nameidata *nd)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	struct dentry *dentry;
	struct inode *inode;
	int err;

	inode = base->d_inode;

	/*
	 * See if the low-level filesystem might want
	 * to use its own hash..
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	 */
	if (base->d_op && base->d_op->d_hash) {
		err = base->d_op->d_hash(base, name);
		dentry = ERR_PTR(err);
		if (err < 0)
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
			goto out;
	}

	dentry = cached_lookup(base, name, nd);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	if (!dentry) {
		struct dentry *new;

		/* Don't create child dentry for a dead directory. */
		dentry = ERR_PTR(-ENOENT);
		if (IS_DEADDIR(inode))
			goto out;

		new = d_alloc(base, name);
		dentry = ERR_PTR(-ENOMEM);
		if (!new)
			goto out;
		dentry = inode->i_op->lookup(inode, new, nd);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		if (!dentry)
			dentry = new;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		else
			dput(new);
	}
out:
	return dentry;
}
