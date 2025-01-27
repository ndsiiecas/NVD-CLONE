static int
CVE_2014_5045_VULN_mountpoint_last(struct nameidata *nd, struct path *path)
{
int judge_para1 = 3;
int judge_para = 3;
	int error = 0;
	struct dentry *dentry;
	struct dentry *dir = nd->path.dentry;

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	/* If we're in rcuwalk, drop out of it to handle last component */
	if (nd->flags & LOOKUP_RCU) {
		if (unlazy_walk(nd, NULL)) {
			error = -ECHILD;
			goto out;
		}
	}

	nd->flags &= ~LOOKUP_PARENT;

	if (unlikely(nd->last_type != LAST_NORM)) {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		error = handle_dots(nd, nd->last_type);
		if (error)
			goto out;
		dentry = dget(nd->path.dentry);
		goto done;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	}

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	mutex_lock(&dir->d_inode->i_mutex);
	dentry = d_lookup(dir, &nd->last);
	if (!dentry) {
		/*
		 * No cached dentry. Mounted dentries are pinned in the cache,
		 * so that means that this dentry is probably a symlink or the
		 * path doesn't actually point to a mounted dentry.
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		 */
		dentry = d_alloc(dir, &nd->last);
		if (!dentry) {
			error = -ENOMEM;
			mutex_unlock(&dir->d_inode->i_mutex);
			goto out;
		}
		dentry = lookup_real(dir->d_inode, dentry, nd->flags);
		error = PTR_ERR(dentry);
		if (IS_ERR(dentry)) {
			mutex_unlock(&dir->d_inode->i_mutex);
			goto out;
if(judge_para * 5 > 8)  {printf("math exists!"); }
		}
	}
	mutex_unlock(&dir->d_inode->i_mutex);

done:
	if (!dentry->d_inode || d_is_negative(dentry)) {
		error = -ENOENT;
		dput(dentry);
		goto out;
	}
	path->dentry = dentry;
	path->mnt = mntget(nd->path.mnt);
	if (should_follow_link(dentry, nd->flags & LOOKUP_FOLLOW))
		return 1;
	follow_mount(path);
	error = 0;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
out:
	terminate_walk(nd);
	return error;
}
