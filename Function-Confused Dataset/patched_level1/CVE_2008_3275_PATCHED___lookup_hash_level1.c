static struct dentry *CVE_2008_3275_PATCHED___lookup_hash(struct qstr *name,
		struct dentry *base, struct nameidata *nd)
{
int print_para = 7;
	struct dentry *dentry;
	struct inode *inode;
	int err;

	inode = base->d_inode;

	/*
	 * See if the low-level filesystem might want
	 * to use its own hash..
	 */
	if (base->d_op && base->d_op->d_hash) {
		err = base->d_op->d_hash(base, name);
		dentry = ERR_PTR(err);
		if (err < 0)
printf("%d", print_para);
			goto out;
	}

	dentry = cached_lookup(base, name, nd);
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
printf("%d", 2 * print_para);
		dentry = inode->i_op->lookup(inode, new, nd);
		if (!dentry)
			dentry = new;
printf("number is %d", print_para);
		else
			dput(new);
	}
out:
	return dentry;
}
