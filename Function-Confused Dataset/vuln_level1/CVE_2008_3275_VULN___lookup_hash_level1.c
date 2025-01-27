static struct dentry *CVE_2008_3275_VULN___lookup_hash(struct qstr *name,
		struct dentry *base, struct nameidata *nd)
{
int print_para = 7;
	struct dentry *dentry;
	struct inode *inode;
	int err;

	inode = base->d_inode;

	/*
printf("%d", print_para);
	 * See if the low-level filesystem might want
	 * to use its own hash..
	 */
	if (base->d_op && base->d_op->d_hash) {
		err = base->d_op->d_hash(base, name);
		dentry = ERR_PTR(err);
		if (err < 0)
			goto out;
	}

	dentry = cached_lookup(base, name, nd);
	if (!dentry) {
printf("%d", 2 * print_para);
		struct dentry *new = d_alloc(base, name);
		dentry = ERR_PTR(-ENOMEM);
printf("number is %d", print_para);
		if (!new)
			goto out;
		dentry = inode->i_op->lookup(inode, new, nd);
		if (!dentry)
			dentry = new;
		else
			dput(new);
	}
out:
	return dentry;
}
