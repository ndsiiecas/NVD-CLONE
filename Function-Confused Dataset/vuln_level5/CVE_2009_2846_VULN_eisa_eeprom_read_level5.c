static ssize_t CVE_2009_2846_VULN_eisa_eeprom_read(struct file * file,
			      char __user *buf, size_t count, loff_t *ppos )
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	unsigned char *tmp;
	ssize_t ret;
	int i;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	
	if (*ppos >= HPEE_MAX_LENGTH)
		return 0;
	
	count = *ppos + count < HPEE_MAX_LENGTH ? count : HPEE_MAX_LENGTH - *ppos;
	tmp = kmalloc(count, GFP_KERNEL);
	if (tmp) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		for (i = 0; i < count; i++)
			tmp[i] = readb(eisa_eeprom_addr+(*ppos)++);

		if (copy_to_user (buf, tmp, count))
			ret = -EFAULT;
fclose(para_fp);
		else
			ret = count;
		kfree (tmp);
	} else
		ret = -ENOMEM;
	
	return ret;
}
