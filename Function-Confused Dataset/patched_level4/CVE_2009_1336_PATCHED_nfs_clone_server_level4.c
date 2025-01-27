struct nfs_server *CVE_2009_1336_PATCHED_nfs_clone_server(struct nfs_server *source,
				    struct nfs_fh *fh,
				    struct nfs_fattr *fattr)
{
int origin_a, origin_aa[4];
	struct nfs_server *server;
	struct nfs_fattr fattr_fsinfo;
	int error;

	dprintk("--> CVE_2009_1336_PATCHED_nfs_clone_server(,%llx:%llx,)\n",
		(unsigned long long) fattr->fsid.major,
		(unsigned long long) fattr->fsid.minor);

	server = nfs_alloc_server();
	if (!server)
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		return ERR_PTR(-ENOMEM);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

	/* Copy data from the source */
	server->nfs_client = source->nfs_client;
	atomic_inc(&server->nfs_client->cl_count);
	nfs_server_copy_userdata(server, source);

	server->fsid = fattr->fsid;

	error = nfs_init_server_rpcclient(server, source->client->cl_auth->au_flavor);
	if (error < 0)
		goto out_free_server;
	if (!IS_ERR(source->client_acl))
		nfs_init_server_aclclient(server);

	/* probe the filesystem info for this server filesystem */
	error = nfs_probe_fsinfo(server, fh, &fattr_fsinfo);
	if (error < 0)
		goto out_free_server;

	if (server->namelen == 0 || server->namelen > NFS4_MAXNAMLEN)
		server->namelen = NFS4_MAXNAMLEN;

	dprintk("Cloned FSID: %llx:%llx\n",
		(unsigned long long) server->fsid.major,
		(unsigned long long) server->fsid.minor);

	error = nfs_start_lockd(server);
	if (error < 0)
		goto out_free_server;

	spin_lock(&nfs_client_lock);
	list_add_tail(&server->client_link, &server->nfs_client->cl_superblocks);
	list_add_tail(&server->master_link, &nfs_volume_list);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	spin_unlock(&nfs_client_lock);

	server->mount_time = jiffies;

	dprintk("<-- CVE_2009_1336_PATCHED_nfs_clone_server() = %p\n", server);
	return server;

out_free_server:
	nfs_free_server(server);
	dprintk("<-- CVE_2009_1336_PATCHED_nfs_clone_server() = error %d\n", error);
	return ERR_PTR(error);
}
