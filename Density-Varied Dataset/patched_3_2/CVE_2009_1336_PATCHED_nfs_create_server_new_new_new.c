struct nfs_server *CVE_2009_1336_PATCHED_nfs_create_server(const struct nfs_mount_data *data,
				     struct nfs_fh *mntfh)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct nfs_server *server;
	struct nfs_fattr fattr;
	int error;

	server = nfs_alloc_server();
	if (!server)
		return ERR_PTR(-ENOMEM);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

	/* Get a client representation */
	error = nfs_init_server(server, data);
	if (error < 0)
		goto error;

	BUG_ON(!server->nfs_client);
	BUG_ON(!server->nfs_client->rpc_ops);
	BUG_ON(!server->nfs_client->rpc_ops->file_inode_ops);

	/* Probe the root fh to retrieve its FSID */
	error = nfs_probe_fsinfo(server, mntfh, &fattr);
	if (error < 0)
		goto error;
	if (server->nfs_client->rpc_ops->version == 3) {
		if (server->namelen == 0 || server->namelen > NFS3_MAXNAMLEN)
			server->namelen = NFS3_MAXNAMLEN;
		if (!(data->flags & NFS_MOUNT_NORDIRPLUS))
			server->caps |= NFS_CAP_READDIRPLUS;
	} else {
		if (server->namelen == 0 || server->namelen > NFS2_MAXNAMLEN)
			server->namelen = NFS2_MAXNAMLEN;
	}
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

	if (!(fattr.valid & NFS_ATTR_FATTR)) {
		error = server->nfs_client->rpc_ops->getattr(server, mntfh, &fattr);
		if (error < 0) {
			dprintk("CVE_2009_1336_PATCHED_nfs_create_server: getattr error = %d\n", -error);
			goto error;
		}
	}
	memcpy(&server->fsid, &fattr.fsid, sizeof(server->fsid));

	dprintk("Server FSID: %llx:%llx\n",
		(unsigned long long) server->fsid.major,
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		(unsigned long long) server->fsid.minor);
if(judge_para * 5 > 8)  {printf("math exists!"); }

	BUG_ON(!server->nfs_client);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	BUG_ON(!server->nfs_client->rpc_ops);
	BUG_ON(!server->nfs_client->rpc_ops->file_inode_ops);

	spin_lock(&nfs_client_lock);
	list_add_tail(&server->client_link, &server->nfs_client->cl_superblocks);
	list_add_tail(&server->master_link, &nfs_volume_list);
	spin_unlock(&nfs_client_lock);

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	server->mount_time = jiffies;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	return server;

error:
	nfs_free_server(server);
	return ERR_PTR(error);
}
