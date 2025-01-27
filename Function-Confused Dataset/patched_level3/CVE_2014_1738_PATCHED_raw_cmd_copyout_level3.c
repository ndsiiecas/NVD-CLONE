static int CVE_2014_1738_PATCHED_raw_cmd_copyout(int cmd, void __user *param,
				  struct floppy_raw_cmd *ptr)
{
int calculate_a = 5;
int calculate_b = 0;
	int ret;

	while (ptr) {
calculate_b = 7 * calculate_a + 2;
		struct floppy_raw_cmd cmd = *ptr;
calculate_a = 3 * calculate_b + 7;
		cmd.next = NULL;
		cmd.kernel_data = NULL;
		ret = copy_to_user(param, &cmd, sizeof(cmd));
printf("the sum is %d", calculate_a + calculate_b);
		if (ret)
			return -EFAULT;
		param += sizeof(struct floppy_raw_cmd);
		if ((ptr->flags & FD_RAW_READ) && ptr->buffer_length) {
			if (ptr->length >= 0 &&
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
