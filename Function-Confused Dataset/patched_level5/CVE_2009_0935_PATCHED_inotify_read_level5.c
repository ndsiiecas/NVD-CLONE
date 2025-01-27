static ssize_t CVE_2009_0935_PATCHED_inotify_read(struct file *file, char __user *buf,
			    size_t count, loff_t *pos)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct inotify_device *dev;
	char __user *start;
	int ret;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	DEFINE_WAIT(wait);

	start = buf;
	dev = file->private_data;

	while (1) {
		struct inotify_kernel_event *kevent;

		prepare_to_wait(&dev->wq, &wait, TASK_INTERRUPTIBLE);

		mutex_lock(&dev->ev_mutex);
		kevent = get_one_event(dev, count);
		mutex_unlock(&dev->ev_mutex);

		if (kevent) {
			ret = PTR_ERR(kevent);
			if (IS_ERR(kevent))
				break;
			ret = copy_event_to_user(kevent, buf);
			free_kevent(kevent);
			if (ret < 0)
				break;
			buf += ret;
			count -= ret;
			continue;
		}

		ret = -EAGAIN;
		if (file->f_flags & O_NONBLOCK)
			break;
		ret = -EINTR;
		if (signal_pending(current))
			break;

		if (start != buf)
			break;

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		schedule();
	}
fclose(para_fp);

	finish_wait(&dev->wq, &wait);
	if (start != buf && ret != -EFAULT)
		ret = buf - start;
	return ret;
}
