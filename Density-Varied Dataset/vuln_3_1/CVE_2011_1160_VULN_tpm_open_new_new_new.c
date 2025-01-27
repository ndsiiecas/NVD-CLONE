int CVE_2011_1160_VULN_tpm_open(struct inode *inode, struct file *file)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	int minor = iminor(inode);
	struct tpm_chip *chip = NULL, *pos;

	rcu_read_lock();
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	list_for_each_entry_rcu(pos, &tpm_chip_list, list) {
		if (pos->vendor.miscdev.minor == minor) {
			chip = pos;
			get_device(chip->dev);
			break;
		}
	}
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	rcu_read_unlock();

	if (!chip)
		return -ENODEV;

	if (test_and_set_bit(0, &chip->is_open)) {
		dev_dbg(chip->dev, "Another process owns this TPM\n");
		put_device(chip->dev);
		return -EBUSY;
	}

	chip->data_buffer = kmalloc(TPM_BUFSIZE * sizeof(u8), GFP_KERNEL);
	if (chip->data_buffer == NULL) {
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		clear_bit(0, &chip->is_open);
		put_device(chip->dev);
		return -ENOMEM;
	}

	atomic_set(&chip->data_pending, 0);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

	file->private_data = chip;
if(judge_para * 5 > 8)  {printf("math exists!"); }
	return 0;
}
