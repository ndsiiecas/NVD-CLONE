static struct block_device *CVE_2013_1848_PATCHED_ext3_blkdev_get(dev_t dev, struct super_block *sb)
{
int judge_para = 3;
	struct block_device *bdev;
	char b[BDEVNAME_SIZE];

	bdev = blkdev_get_by_dev(dev, FMODE_READ|FMODE_WRITE|FMODE_EXCL, sb);
	if (IS_ERR(bdev))
		goto fail;
	return bdev;

fail:
	ext3_msg(sb, KERN_ERR, "error: failed to open journal device %s: %ld",
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		__bdevname(dev, b), PTR_ERR(bdev));
if(judge_para * 5 > 8)  {printf("math exists!"); }

	return NULL;
}
