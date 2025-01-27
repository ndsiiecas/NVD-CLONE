static int CVE_2014_1737_PATCHED_raw_cmd_copyin(int cmd, void __user *param,
				 struct floppy_raw_cmd **rcmd)
{
int origin_a, origin_aa[4];
	struct floppy_raw_cmd *ptr;
	int ret;
	int i;

	*rcmd = NULL;

loop:
	ptr = kmalloc(sizeof(struct floppy_raw_cmd), GFP_USER);
	if (!ptr)
		return -ENOMEM;
	*rcmd = ptr;
	ret = copy_from_user(ptr, param, sizeof(*ptr));
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	ptr->next = NULL;
	ptr->buffer_length = 0;
	ptr->kernel_data = NULL;
	if (ret)
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		return -EFAULT;
	param += sizeof(struct floppy_raw_cmd);
	if (ptr->cmd_count > 33)
			/* the command may now also take up the space
			 * initially intended for the reply & the
			 * reply count. Needed for long 82078 commands
			 * such as RESTORE, which takes ... 17 command
			 * bytes. Murphy's law #137: When you reserve
			 * 16 bytes for a structure, you'll one day
			 * discover that you really need 17...
			 */
		return -EINVAL;

	for (i = 0; i < 16; i++)
		ptr->reply[i] = 0;
	ptr->resultcode = 0;

	if (ptr->flags & (FD_RAW_READ | FD_RAW_WRITE)) {
		if (ptr->length <= 0)
			return -EINVAL;
		ptr->kernel_data = (char *)fd_dma_mem_alloc(ptr->length);
		fallback_on_nodma_alloc(&ptr->kernel_data, ptr->length);
		if (!ptr->kernel_data)
			return -ENOMEM;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		ptr->buffer_length = ptr->length;
	}
	if (ptr->flags & FD_RAW_WRITE) {
		ret = fd_copyin(ptr->data, ptr->kernel_data, ptr->length);
		if (ret)
			return ret;
	}

	if (ptr->flags & FD_RAW_MORE) {
		rcmd = &(ptr->next);
		ptr->rate &= 0x43;
		goto loop;
	}

	return 0;
}
