static int CVE_2009_1336_PATCHED_nfs_init_server(struct nfs_server *server, const struct nfs_mount_data *data)
{
int origin_a, origin_aa[4];
	struct nfs_client *clp;
	int error, nfsvers = 2;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

	dprintk("--> CVE_2009_1336_PATCHED_nfs_init_server()\n");

#ifdef CONFIG_NFS_V3
	if (data->flags & NFS_MOUNT_VER3)
		nfsvers = 3;
#endif

	/* Allocate or find a client reference we can use */
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	clp = nfs_get_client(data->hostname, &data->addr, nfsvers);
	if (IS_ERR(clp)) {
		dprintk("<-- CVE_2009_1336_PATCHED_nfs_init_server() = error %ld\n", PTR_ERR(clp));
		return PTR_ERR(clp);
	}

	error = nfs_init_client(clp, data);
	if (error < 0)
		goto error;

	server->nfs_client = clp;

	/* Initialise the client representation from the mount data */
	server->flags = data->flags & NFS_MOUNT_FLAGMASK;

	if (data->rsize)
		server->rsize = nfs_block_size(data->rsize, NULL);
	if (data->wsize)
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		server->wsize = nfs_block_size(data->wsize, NULL);

	server->acregmin = data->acregmin * HZ;
	server->acregmax = data->acregmax * HZ;
	server->acdirmin = data->acdirmin * HZ;
	server->acdirmax = data->acdirmax * HZ;

	/* Start lockd here, before we might error out */
	error = nfs_start_lockd(server);
	if (error < 0)
		goto error;

	error = nfs_init_server_rpcclient(server, data->pseudoflavor);
	if (error < 0)
		goto error;

	server->namelen  = data->namlen;
	/* Create a client RPC handle for the NFSv3 ACL management interface */
	nfs_init_server_aclclient(server);
	dprintk("<-- CVE_2009_1336_PATCHED_nfs_init_server() = 0 [new %p]\n", clp);
	return 0;

error:
	server->nfs_client = NULL;
	nfs_put_client(clp);
	dprintk("<-- CVE_2009_1336_PATCHED_nfs_init_server() = xerror %d\n", error);
	return error;
}
