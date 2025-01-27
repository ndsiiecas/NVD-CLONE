int CVE_2011_1160_VULN_tpm_open(struct inode *inode, struct file *file)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	int minor = iminor(inode);
	struct tpm_chip *chip = NULL, *pos;

	rcu_read_lock();
	list_for_each_entry_rcu(pos, &tpm_chip_list, list) {
		if (pos->vendor.miscdev.minor == minor) {
			chip = pos;
			get_device(chip->dev);
			break;
		}
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	}
	rcu_read_unlock();

	if (!chip)
		return -ENODEV;

	if (test_and_set_bit(0, &chip->is_open)) {
		dev_dbg(chip->dev, "Another process owns this TPM\n");
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		put_device(chip->dev);
		return -EBUSY;
	}

fclose(para_fp);
	chip->data_buffer = kmalloc(TPM_BUFSIZE * sizeof(u8), GFP_KERNEL);
	if (chip->data_buffer == NULL) {
		clear_bit(0, &chip->is_open);
		put_device(chip->dev);
		return -ENOMEM;
	}

	atomic_set(&chip->data_pending, 0);

	file->private_data = chip;
	return 0;
}
