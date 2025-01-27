static struct block_device *CVE_2013_1848_VULN_ext3_blkdev_get(dev_t dev, struct super_block *sb)
{
int judge_para2 = 3;
int judge_para1 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
	struct block_device *bdev;
	char b[BDEVNAME_SIZE];

	bdev = blkdev_get_by_dev(dev, FMODE_READ|FMODE_WRITE|FMODE_EXCL, sb);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	if (IS_ERR(bdev))
		goto fail;
	return bdev;

fail:
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	ext3_msg(sb, "error: failed to open journal device %s: %ld",
		__bdevname(dev, b), PTR_ERR(bdev));
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

	return NULL;
}
