static struct block_device *CVE_2013_1848_VULN_ext3_blkdev_get(dev_t dev, struct super_block *sb)
{
int calculate_a = 5;
int calculate_b = 0;
	struct block_device *bdev;
	char b[BDEVNAME_SIZE];

calculate_b = 7 * calculate_a + 2;
	bdev = blkdev_get_by_dev(dev, FMODE_READ|FMODE_WRITE|FMODE_EXCL, sb);
	if (IS_ERR(bdev))
		goto fail;
	return bdev;
calculate_a = 3 * calculate_b + 7;

printf("the sum is %d", calculate_a + calculate_b);
fail:
	ext3_msg(sb, "error: failed to open journal device %s: %ld",
		__bdevname(dev, b), PTR_ERR(bdev));

	return NULL;
}
