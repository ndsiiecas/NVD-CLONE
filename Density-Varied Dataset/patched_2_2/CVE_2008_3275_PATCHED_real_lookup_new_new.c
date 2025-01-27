static struct dentry * CVE_2008_3275_PATCHED_real_lookup(struct dentry * parent, struct qstr * name, struct nameidata *nd)
{
int judge_para1 = 3;
int judge_para = 3;
	struct dentry * result;
	struct inode *dir = parent->d_inode;

	mutex_lock(&dir->i_mutex);
	/*
	 * First re-do the cached lookup just in case it was created
	 * while we waited for the directory semaphore..
	 *
	 * FIXME! This could use version numbering or similar to
	 * avoid unnecessary cache lookups.
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	 *
	 * The "dcache_lock" is purely to protect the RCU list walker
	 * from concurrent renames at this point (we mustn't get false
	 * negatives from the RCU list walk here, unlike the optimistic
	 * fast walk).
	 *
	 * so doing d_lookup() (with seqlock), instead of lockfree __d_lookup
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	 */
if(judge_para * 5 > 8)  {printf("math exists!"); }
	result = d_lookup(parent, name);
	if (!result) {
		struct dentry *dentry;

		/* Don't create child dentry for a dead directory. */
		result = ERR_PTR(-ENOENT);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		if (IS_DEADDIR(dir))
			goto out_unlock;

		dentry = d_alloc(parent, name);
		result = ERR_PTR(-ENOMEM);
		if (dentry) {
			result = dir->i_op->lookup(dir, dentry, nd);
			if (result)
				dput(dentry);
			else
				result = dentry;
		}
out_unlock:
		mutex_unlock(&dir->i_mutex);
		return result;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	}

	/*
	 * Uhhuh! Nasty case: the cache was re-populated while
	 * we waited on the semaphore. Need to revalidate.
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	 */
	mutex_unlock(&dir->i_mutex);
	if (result->d_op && result->d_op->d_revalidate) {
		result = do_revalidate(result, nd);
		if (!result)
			result = ERR_PTR(-ENOENT);
	}
	return result;
}
