static int CVE_2014_1738_VULN_raw_cmd_copyout(int cmd, void __user *param,
				  struct floppy_raw_cmd *ptr)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	int ret;

	while (ptr) {
		ret = copy_to_user(param, ptr, sizeof(*ptr));
		if (ret)
			return -EFAULT;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		param += sizeof(struct floppy_raw_cmd);
		if ((ptr->flags & FD_RAW_READ) && ptr->buffer_length) {
fclose(para_fp);
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
