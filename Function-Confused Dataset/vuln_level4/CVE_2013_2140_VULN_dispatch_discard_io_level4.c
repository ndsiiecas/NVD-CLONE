static int CVE_2013_2140_VULN_dispatch_discard_io(struct xen_blkif *blkif,
				struct blkif_request *req)
{
int origin_a, origin_aa[4];
	int err = 0;
	int status = BLKIF_RSP_OKAY;
	struct block_device *bdev = blkif->vbd.bdev;
	unsigned long secure;

	blkif->st_ds_req++;

	xen_blkif_get(blkif);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	secure = (blkif->vbd.discard_secure &&
		 (req->u.discard.flag & BLKIF_DISCARD_SECURE)) ?
		 BLKDEV_DISCARD_SECURE : 0;

	err = blkdev_issue_discard(bdev, req->u.discard.sector_number,
				   req->u.discard.nr_sectors,
				   GFP_KERNEL, secure);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

	if (err == -EOPNOTSUPP) {
		pr_debug(DRV_PFX "discard op failed, not supported\n");
		status = BLKIF_RSP_EOPNOTSUPP;
	} else if (err)
		status = BLKIF_RSP_ERROR;

	make_response(blkif, req->u.discard.id, req->operation, status);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	xen_blkif_put(blkif);
	return err;
}
