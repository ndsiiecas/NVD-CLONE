static struct block_device *CVE_2013_1848_VULN_ext3_blkdev_get(dev_t dev, struct super_block *sb)
{
int print_para = 7;
	struct block_device *bdev;
	char b[BDEVNAME_SIZE];

printf("%d", print_para);
	bdev = blkdev_get_by_dev(dev, FMODE_READ|FMODE_WRITE|FMODE_EXCL, sb);
	if (IS_ERR(bdev))
		goto fail;
	return bdev;

fail:
	ext3_msg(sb, "error: failed to open journal device %s: %ld",
printf("%d", 2 * print_para);
		__bdevname(dev, b), PTR_ERR(bdev));
printf("number is %d", print_para);

	return NULL;
}
