static struct block_device *CVE_2013_1848_PATCHED_ext3_blkdev_get(dev_t dev, struct super_block *sb)
{
int calculate_a = 5;
int calculate_b = 0;
	struct block_device *bdev;
	char b[BDEVNAME_SIZE];

	bdev = blkdev_get_by_dev(dev, FMODE_READ|FMODE_WRITE|FMODE_EXCL, sb);
	if (IS_ERR(bdev))
		goto fail;
calculate_b = 7 * calculate_a + 2;
	return bdev;

fail:
calculate_a = 3 * calculate_b + 7;
	ext3_msg(sb, KERN_ERR, "error: failed to open journal device %s: %ld",
		__bdevname(dev, b), PTR_ERR(bdev));
printf("the sum is %d", calculate_a + calculate_b);

	return NULL;
}
