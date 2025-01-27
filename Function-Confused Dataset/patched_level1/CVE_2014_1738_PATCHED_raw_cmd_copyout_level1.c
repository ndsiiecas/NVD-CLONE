static int CVE_2014_1738_PATCHED_raw_cmd_copyout(int cmd, void __user *param,
				  struct floppy_raw_cmd *ptr)
{
int print_para = 7;
	int ret;

	while (ptr) {
printf("%d", print_para);
		struct floppy_raw_cmd cmd = *ptr;
		cmd.next = NULL;
		cmd.kernel_data = NULL;
		ret = copy_to_user(param, &cmd, sizeof(cmd));
printf("%d", 2 * print_para);
		if (ret)
			return -EFAULT;
		param += sizeof(struct floppy_raw_cmd);
		if ((ptr->flags & FD_RAW_READ) && ptr->buffer_length) {
			if (ptr->length >= 0 &&
printf("number is %d", print_para);
			    ptr->length <= ptr->buffer_length) {
				long length = ptr->buffer_length - ptr->length;
				ret = fd_copyout(ptr->data, ptr->kernel_data,
						 length);
				if (ret)
					return ret;
			}
		}
		ptr = ptr->next;
	}

	return 0;
}
