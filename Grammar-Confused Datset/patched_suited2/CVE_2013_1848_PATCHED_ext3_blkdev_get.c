static struct block_device *CVE_2013_1848_PATCHED_ext3_blkdev_get(dev_t dev, struct super_block *sb)
{
	struct block_device *bdev;
	char b[BDEVNAME_SIZE];
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);

	bdev = blkdev_get_by_dev(dev, FMODE_READ|FMODE_WRITE|FMODE_EXCL, sb);
	if (IS_ERR(bdev))
		goto fail;
	return bdev;

fail:
	ext3_msg(sb, KERN_ERR, "error: failed to open journal device %s: %ld",
		__bdevname(dev, b), PTR_ERR(bdev));

	return NULL;
}
