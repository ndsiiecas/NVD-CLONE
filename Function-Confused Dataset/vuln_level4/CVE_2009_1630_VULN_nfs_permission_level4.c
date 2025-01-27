int CVE_2009_1630_VULN_nfs_permission(struct inode *inode, int mask)
{
int origin_a, origin_aa[4];
	struct rpc_cred *cred;
	int res = 0;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

	nfs_inc_stats(inode, NFSIOS_VFSACCESS);

	if ((mask & (MAY_READ | MAY_WRITE | MAY_EXEC)) == 0)
		goto out;
	/* Is this sys_access() ? */
	if (mask & MAY_ACCESS)
		goto force_lookup;

	switch (inode->i_mode & S_IFMT) {
		case S_IFLNK:
			goto out;
		case S_IFREG:
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
			/* NFSv4 has atomic_open... */
			if (nfs_server_capable(inode, NFS_CAP_ATOMIC_OPEN)
					&& (mask & MAY_OPEN))
				goto out;
			break;
		case S_IFDIR:
			/*
			 * Optimize away all write operations, since the server
			 * will check permissions when we perform the op.
			 */
			if ((mask & MAY_WRITE) && !(mask & MAY_READ))
				goto out;
	}

force_lookup:
	if (!NFS_PROTO(inode)->access)
		goto out_notsup;

	cred = rpc_lookup_cred();
	if (!IS_ERR(cred)) {
		res = nfs_do_access(inode, cred, mask);
		put_rpccred(cred);
	} else
		res = PTR_ERR(cred);
out:
	if (!res && (mask & MAY_EXEC) && !execute_ok(inode))
		res = -EACCES;

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	dfprintk(VFS, "NFS: permission(%s/%ld), mask=0x%x, res=%d\n",
		inode->i_sb->s_id, inode->i_ino, mask, res);
	return res;
out_notsup:
	res = nfs_revalidate_inode(NFS_SERVER(inode), inode);
	if (res == 0)
		res = generic_permission(inode, mask, NULL);
	goto out;
}
