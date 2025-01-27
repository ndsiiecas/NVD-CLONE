static struct block_device *CVE_2013_1848_PATCHED_ext3_blkdev_get(dev_t dev, struct super_block *sb)
{
int print_para = 7;
	struct block_device *bdev;
	char b[BDEVNAME_SIZE];

	bdev = blkdev_get_by_dev(dev, FMODE_READ|FMODE_WRITE|FMODE_EXCL, sb);
	if (IS_ERR(bdev))
		goto fail;
	return bdev;
printf("%d", print_para);

fail:
	ext3_msg(sb, KERN_ERR, "error: failed to open journal device %s: %ld",
printf("%d", 2 * print_para);
printf("number is %d", print_para);
		__bdevname(dev, b), PTR_ERR(bdev));

	return NULL;
}
