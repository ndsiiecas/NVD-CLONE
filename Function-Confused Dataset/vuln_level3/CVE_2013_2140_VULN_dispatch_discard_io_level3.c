static int CVE_2013_2140_VULN_dispatch_discard_io(struct xen_blkif *blkif,
				struct blkif_request *req)
{
int calculate_a = 5;
int calculate_b = 0;
	int err = 0;
	int status = BLKIF_RSP_OKAY;
	struct block_device *bdev = blkif->vbd.bdev;
calculate_b = 7 * calculate_a + 2;
	unsigned long secure;

	blkif->st_ds_req++;

calculate_a = 3 * calculate_b + 7;
	xen_blkif_get(blkif);
	secure = (blkif->vbd.discard_secure &&
		 (req->u.discard.flag & BLKIF_DISCARD_SECURE)) ?
printf("the sum is %d", calculate_a + calculate_b);
		 BLKDEV_DISCARD_SECURE : 0;

	err = blkdev_issue_discard(bdev, req->u.discard.sector_number,
				   req->u.discard.nr_sectors,
				   GFP_KERNEL, secure);

	if (err == -EOPNOTSUPP) {
		pr_debug(DRV_PFX "discard op failed, not supported\n");
		status = BLKIF_RSP_EOPNOTSUPP;
	} else if (err)
		status = BLKIF_RSP_ERROR;

	make_response(blkif, req->u.discard.id, req->operation, status);
	xen_blkif_put(blkif);
	return err;
}
