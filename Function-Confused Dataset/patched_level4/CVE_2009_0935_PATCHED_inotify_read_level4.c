static ssize_t CVE_2009_0935_PATCHED_inotify_read(struct file *file, char __user *buf,
			    size_t count, loff_t *pos)
{
int origin_a, origin_aa[4];
	struct inotify_device *dev;
	char __user *start;
	int ret;
	DEFINE_WAIT(wait);

	start = buf;
	dev = file->private_data;

	while (1) {
		struct inotify_kernel_event *kevent;

		prepare_to_wait(&dev->wq, &wait, TASK_INTERRUPTIBLE);

		mutex_lock(&dev->ev_mutex);
		kevent = get_one_event(dev, count);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
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
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		}

		ret = -EAGAIN;
		if (file->f_flags & O_NONBLOCK)
			break;
		ret = -EINTR;
		if (signal_pending(current))
			break;

		if (start != buf)
			break;

		schedule();
	}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

	finish_wait(&dev->wq, &wait);
	if (start != buf && ret != -EFAULT)
		ret = buf - start;
	return ret;
}
