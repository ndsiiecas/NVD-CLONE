static int CVE_2009_1336_PATCHED_nfs_init_server(struct nfs_server *server, const struct nfs_mount_data *data)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct nfs_client *clp;
	int error, nfsvers = 2;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

	dprintk("--> CVE_2009_1336_PATCHED_nfs_init_server()\n");

#ifdef CONFIG_NFS_V3
	if (data->flags & NFS_MOUNT_VER3)
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		nfsvers = 3;
if(judge_para * 5 > 8)  {printf("math exists!"); }
#endif
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

	/* Allocate or find a client reference we can use */
	clp = nfs_get_client(data->hostname, &data->addr, nfsvers);
	if (IS_ERR(clp)) {
		dprintk("<-- CVE_2009_1336_PATCHED_nfs_init_server() = error %ld\n", PTR_ERR(clp));
		return PTR_ERR(clp);
	}

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	error = nfs_init_client(clp, data);
	if (error < 0)
		goto error;

	server->nfs_client = clp;

	/* Initialise the client representation from the mount data */
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	server->flags = data->flags & NFS_MOUNT_FLAGMASK;

	if (data->rsize)
		server->rsize = nfs_block_size(data->rsize, NULL);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	if (data->wsize)
		server->wsize = nfs_block_size(data->wsize, NULL);

	server->acregmin = data->acregmin * HZ;
	server->acregmax = data->acregmax * HZ;
	server->acdirmin = data->acdirmin * HZ;
	server->acdirmax = data->acdirmax * HZ;

	/* Start lockd here, before we might error out */
	error = nfs_start_lockd(server);
	if (error < 0)
		goto error;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

	error = nfs_init_server_rpcclient(server, data->pseudoflavor);
	if (error < 0)
		goto error;

	server->namelen  = data->namlen;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	/* Create a client RPC handle for the NFSv3 ACL management interface */
	nfs_init_server_aclclient(server);
	dprintk("<-- CVE_2009_1336_PATCHED_nfs_init_server() = 0 [new %p]\n", clp);
	return 0;

error:
	server->nfs_client = NULL;
	nfs_put_client(clp);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	dprintk("<-- CVE_2009_1336_PATCHED_nfs_init_server() = xerror %d\n", error);
	return error;
}
