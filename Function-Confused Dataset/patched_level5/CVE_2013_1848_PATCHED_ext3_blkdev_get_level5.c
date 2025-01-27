static struct block_device *CVE_2013_1848_PATCHED_ext3_blkdev_get(dev_t dev, struct super_block *sb)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	struct block_device *bdev;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	char b[BDEVNAME_SIZE];

	bdev = blkdev_get_by_dev(dev, FMODE_READ|FMODE_WRITE|FMODE_EXCL, sb);
	if (IS_ERR(bdev))
		goto fail;
	return bdev;

fail:
	ext3_msg(sb, KERN_ERR, "error: failed to open journal device %s: %ld",
		__bdevname(dev, b), PTR_ERR(bdev));
fclose(para_fp);

	return NULL;
}
