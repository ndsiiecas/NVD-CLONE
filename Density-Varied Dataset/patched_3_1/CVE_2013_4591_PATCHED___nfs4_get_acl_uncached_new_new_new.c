static ssize_t CVE_2013_4591_PATCHED___nfs4_get_acl_uncached(struct inode *inode, void *buf, size_t buflen)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct page *pages[NFS4ACL_MAXPAGES] = {NULL, };
	struct nfs_getaclargs args = {
		.fh = NFS_FH(inode),
		.acl_pages = pages,
		.acl_len = buflen,
	};
	struct nfs_getaclres res = {
		.acl_len = buflen,
	};
	struct rpc_message msg = {
		.rpc_proc = &nfs4_procedures[NFSPROC4_CLNT_GETACL],
		.rpc_argp = &args,
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		.rpc_resp = &res,
	};
	unsigned int npages = DIV_ROUND_UP(buflen, PAGE_SIZE);
	int ret = -ENOMEM, i;

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	/* As long as we're doing a round trip to the server anyway,
	 * let's be prepared for a page of acl data. */
	if (npages == 0)
		npages = 1;
	if (npages > ARRAY_SIZE(pages))
		return -ERANGE;

	for (i = 0; i < npages; i++) {
		pages[i] = alloc_page(GFP_KERNEL);
		if (!pages[i])
			goto out_free;
	}

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	/* for decoding across pages */
	res.acl_scratch = alloc_page(GFP_KERNEL);
	if (!res.acl_scratch)
		goto out_free;

	args.acl_len = npages * PAGE_SIZE;
	args.acl_pgbase = 0;

	dprintk("%s  buf %p buflen %zu npages %d args.acl_len %zu\n",
		__func__, buf, buflen, npages, args.acl_len);
	ret = nfs4_call_sync(NFS_SERVER(inode)->client, NFS_SERVER(inode),
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			     &msg, &args.seq_args, &res.seq_res, 0);
	if (ret)
		goto out_free;

	/* Handle the case where the passed-in buffer is too short */
	if (res.acl_flags & NFS4_ACL_TRUNC) {
		/* Did the user only issue a request for the acl length? */
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		if (buf == NULL)
			goto out_ok;
		ret = -ERANGE;
		goto out_free;
	}
	nfs4_write_cached_acl(inode, pages, res.acl_data_offset, res.acl_len);
	if (buf) {
		if (res.acl_len > buflen) {
			ret = -ERANGE;
			goto out_free;
		}
if(judge_para * 5 > 8)  {printf("math exists!"); }
		_copy_from_pages(buf, pages, res.acl_data_offset, res.acl_len);
	}
out_ok:
	ret = res.acl_len;
out_free:
	for (i = 0; i < npages; i++)
		if (pages[i])
			__free_page(pages[i]);
	if (res.acl_scratch)
		__free_page(res.acl_scratch);
	return ret;
}
