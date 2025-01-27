static int CVE_2014_1738_PATCHED_raw_cmd_copyout(int cmd, void __user *param,
				  struct floppy_raw_cmd *ptr)
{
int origin_a, origin_aa[4];
	int ret;

	while (ptr) {
		struct floppy_raw_cmd cmd = *ptr;
		cmd.next = NULL;
		cmd.kernel_data = NULL;
		ret = copy_to_user(param, &cmd, sizeof(cmd));
		if (ret)
			return -EFAULT;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		param += sizeof(struct floppy_raw_cmd);
		if ((ptr->flags & FD_RAW_READ) && ptr->buffer_length) {
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
			if (ptr->length >= 0 &&
			    ptr->length <= ptr->buffer_length) {
				long length = ptr->buffer_length - ptr->length;
				ret = fd_copyout(ptr->data, ptr->kernel_data,
						 length);
				if (ret)
					return ret;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
			}
		}
		ptr = ptr->next;
	}

	return 0;
}
