static int CVE_2013_2140_PATCHED_dispatch_discard_io(struct xen_blkif *blkif,
				struct blkif_request *req)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	int err = 0;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	int status = BLKIF_RSP_OKAY;
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
		status = BLKIF_RSP_EOPNOTSUPP;
	} else if (err)
		status = BLKIF_RSP_ERROR;

fclose(para_fp);
	make_response(blkif, req->u.discard.id, req->operation, status);
	xen_blkif_put(blkif);
	return err;
}
