static struct dentry *CVE_2008_3275_VULN___lookup_hash(struct qstr *name,
		struct dentry *base, struct nameidata *nd)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct dentry *dentry;
	struct inode *inode;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	int err;

	inode = base->d_inode;

	/*
	 * See if the low-level filesystem might want
	 * to use its own hash..
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	 */
	if (base->d_op && base->d_op->d_hash) {
		err = base->d_op->d_hash(base, name);
		dentry = ERR_PTR(err);
		if (err < 0)
			goto out;
	}

	dentry = cached_lookup(base, name, nd);
	if (!dentry) {
		struct dentry *new = d_alloc(base, name);
fclose(para_fp);
		dentry = ERR_PTR(-ENOMEM);
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
