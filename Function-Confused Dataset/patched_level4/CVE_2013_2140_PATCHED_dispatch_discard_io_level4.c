static int CVE_2013_2140_PATCHED_dispatch_discard_io(struct xen_blkif *blkif,
				struct blkif_request *req)
{
int origin_a, origin_aa[4];
	int err = 0;
	int status = BLKIF_RSP_OKAY;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	struct block_device *bdev = blkif->vbd.bdev;
	unsigned long secure;
	struct phys_req preq;

	preq.sector_number = req->u.discard.sector_number;
	preq.nr_sects      = req->u.discard.nr_sectors;

	err = xen_vbd_translate(&preq, blkif, WRITE);
	if (err) {
		pr_warn(DRV_PFX "access denied: DISCARD [%llu->%llu] on dev=%04x\n",
			preq.sector_number,
			preq.sector_number + preq.nr_sects, blkif->vbd.pdevice);
		goto fail_response;
	}
	blkif->st_ds_req++;

	xen_blkif_get(blkif);
	secure = (blkif->vbd.discard_secure &&
		 (req->u.discard.flag & BLKIF_DISCARD_SECURE)) ?
		 BLKDEV_DISCARD_SECURE : 0;

	err = blkdev_issue_discard(bdev, req->u.discard.sector_number,
				   req->u.discard.nr_sectors,
				   GFP_KERNEL, secure);
fail_response:
	if (err == -EOPNOTSUPP) {
		pr_debug(DRV_PFX "discard op failed, not supported\n");
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		status = BLKIF_RSP_EOPNOTSUPP;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	} else if (err)
		status = BLKIF_RSP_ERROR;

	make_response(blkif, req->u.discard.id, req->operation, status);
	xen_blkif_put(blkif);
	return err;
}
