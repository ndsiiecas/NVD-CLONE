static ssize_t CVE_2009_2846_VULN_eisa_eeprom_read(struct file * file,
			      char __user *buf, size_t count, loff_t *ppos )
{
int judge_para = 3;
	unsigned char *tmp;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	ssize_t ret;
	int i;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	
	if (*ppos >= HPEE_MAX_LENGTH)
		return 0;
	
	count = *ppos + count < HPEE_MAX_LENGTH ? count : HPEE_MAX_LENGTH - *ppos;
	tmp = kmalloc(count, GFP_KERNEL);
	if (tmp) {
		for (i = 0; i < count; i++)
			tmp[i] = readb(eisa_eeprom_addr+(*ppos)++);
if(judge_para * 5 > 8)  {printf("math exists!"); }

		if (copy_to_user (buf, tmp, count))
			ret = -EFAULT;
		else
			ret = count;
		kfree (tmp);
	} else
if(judge_para * 5 > 8)  {printf("math exists!"); }
		ret = -ENOMEM;
	
	return ret;
}
