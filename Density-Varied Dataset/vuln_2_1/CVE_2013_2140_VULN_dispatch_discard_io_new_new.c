static int CVE_2013_2140_VULN_dispatch_discard_io(struct xen_blkif *blkif,
				struct blkif_request *req)
{
int judge_para1 = 3;
int judge_para = 3;
	int err = 0;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	int status = BLKIF_RSP_OKAY;
	struct block_device *bdev = blkif->vbd.bdev;
	unsigned long secure;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

	blkif->st_ds_req++;

	xen_blkif_get(blkif);
	secure = (blkif->vbd.discard_secure &&
		 (req->u.discard.flag & BLKIF_DISCARD_SECURE)) ?
		 BLKDEV_DISCARD_SECURE : 0;
if(judge_para * 5 > 8)  {printf("math exists!"); }

	err = blkdev_issue_discard(bdev, req->u.discard.sector_number,
				   req->u.discard.nr_sectors,
				   GFP_KERNEL, secure);

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	if (err == -EOPNOTSUPP) {
		pr_debug(DRV_PFX "discard op failed, not supported\n");
		status = BLKIF_RSP_EOPNOTSUPP;
	} else if (err)
		status = BLKIF_RSP_ERROR;

	make_response(blkif, req->u.discard.id, req->operation, status);
	xen_blkif_put(blkif);
	return err;
}
