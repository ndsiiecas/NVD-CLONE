static int
CVE_2014_5045_VULN_mountpoint_last(struct nameidata *nd, struct path *path)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	int error = 0;
	struct dentry *dentry;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	struct dentry *dir = nd->path.dentry;

	/* If we're in rcuwalk, drop out of it to handle last component */
	if (nd->flags & LOOKUP_RCU) {
		if (unlazy_walk(nd, NULL)) {
			error = -ECHILD;
			goto out;
		}
	}

	nd->flags &= ~LOOKUP_PARENT;

	if (unlikely(nd->last_type != LAST_NORM)) {
		error = handle_dots(nd, nd->last_type);
		if (error)
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
			goto out;
		dentry = dget(nd->path.dentry);
		goto done;
	}

	mutex_lock(&dir->d_inode->i_mutex);
	dentry = d_lookup(dir, &nd->last);
	if (!dentry) {
		/*
		 * No cached dentry. Mounted dentries are pinned in the cache,
		 * so that means that this dentry is probably a symlink or the
		 * path doesn't actually point to a mounted dentry.
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
		}
fclose(para_fp);
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
out:
	terminate_walk(nd);
	return error;
}
