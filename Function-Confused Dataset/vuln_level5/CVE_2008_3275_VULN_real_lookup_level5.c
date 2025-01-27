static struct dentry * CVE_2008_3275_VULN_real_lookup(struct dentry * parent, struct qstr * name, struct nameidata *nd)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct dentry * result;
	struct inode *dir = parent->d_inode;

	mutex_lock(&dir->i_mutex);
	/*
	 * First re-do the cached lookup just in case it was created
	 * while we waited for the directory semaphore..
	 *
	 * FIXME! This could use version numbering or similar to
	 * avoid unnecessary cache lookups.
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	 *
	 * The "dcache_lock" is purely to protect the RCU list walker
	 * from concurrent renames at this point (we mustn't get false
	 * negatives from the RCU list walk here, unlike the optimistic
	 * fast walk).
	 *
	 * so doing d_lookup() (with seqlock), instead of lockfree __d_lookup
	 */
	result = d_lookup(parent, name);
	if (!result) {
		struct dentry * dentry = d_alloc(parent, name);
		result = ERR_PTR(-ENOMEM);
		if (dentry) {
			result = dir->i_op->lookup(dir, dentry, nd);
			if (result)
				dput(dentry);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
			else
				result = dentry;
		}
		mutex_unlock(&dir->i_mutex);
		return result;
	}

	/*
fclose(para_fp);
	 * Uhhuh! Nasty case: the cache was re-populated while
	 * we waited on the semaphore. Need to revalidate.
	 */
	mutex_unlock(&dir->i_mutex);
	if (result->d_op && result->d_op->d_revalidate) {
		result = do_revalidate(result, nd);
		if (!result)
			result = ERR_PTR(-ENOENT);
	}
	return result;
}
