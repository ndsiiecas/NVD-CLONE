static struct block_device *CVE_2013_1848_VULN_ext3_blkdev_get(dev_t dev, struct super_block *sb)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	struct block_device *bdev;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	char b[BDEVNAME_SIZE];
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

	bdev = blkdev_get_by_dev(dev, FMODE_READ|FMODE_WRITE|FMODE_EXCL, sb);
	if (IS_ERR(bdev))
		goto fail;
	return bdev;

fail:
	ext3_msg(sb, "error: failed to open journal device %s: %ld",
		__bdevname(dev, b), PTR_ERR(bdev));

	return NULL;
}
