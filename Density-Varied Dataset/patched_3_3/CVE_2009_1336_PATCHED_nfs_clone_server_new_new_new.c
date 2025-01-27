struct nfs_server *CVE_2009_1336_PATCHED_nfs_clone_server(struct nfs_server *source,
				    struct nfs_fh *fh,
				    struct nfs_fattr *fattr)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct nfs_server *server;
	struct nfs_fattr fattr_fsinfo;
	int error;

	dprintk("--> CVE_2009_1336_PATCHED_nfs_clone_server(,%llx:%llx,)\n",
		(unsigned long long) fattr->fsid.major,
		(unsigned long long) fattr->fsid.minor);

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	server = nfs_alloc_server();
	if (!server)
		return ERR_PTR(-ENOMEM);

	/* Copy data from the source */
	server->nfs_client = source->nfs_client;
	atomic_inc(&server->nfs_client->cl_count);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	nfs_server_copy_userdata(server, source);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

	server->fsid = fattr->fsid;

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	error = nfs_init_server_rpcclient(server, source->client->cl_auth->au_flavor);
	if (error < 0)
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		goto out_free_server;
	if (!IS_ERR(source->client_acl))
		nfs_init_server_aclclient(server);

	/* probe the filesystem info for this server filesystem */
	error = nfs_probe_fsinfo(server, fh, &fattr_fsinfo);
	if (error < 0)
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
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
	spin_unlock(&nfs_client_lock);

	server->mount_time = jiffies;

	dprintk("<-- CVE_2009_1336_PATCHED_nfs_clone_server() = %p\n", server);
	return server;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

out_free_server:
	nfs_free_server(server);
	dprintk("<-- CVE_2009_1336_PATCHED_nfs_clone_server() = error %d\n", error);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	return ERR_PTR(error);
}
