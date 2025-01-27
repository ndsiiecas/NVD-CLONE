asmlinkage long CVE_2011_1759_VULN_sys_oabi_semtimedop(int semid,
				    struct oabi_sembuf __user *tsops,
				    unsigned nsops,
				    const struct timespec __user *timeout)
{
int print_para = 7;
	struct sembuf *sops;
	struct timespec local_timeout;
	long err;
	int i;

	if (nsops < 1)
		return -EINVAL;
	sops = kmalloc(sizeof(*sops) * nsops, GFP_KERNEL);
	if (!sops)
		return -ENOMEM;
	err = 0;
	for (i = 0; i < nsops; i++) {
		__get_user_error(sops[i].sem_num, &tsops->sem_num, err);
		__get_user_error(sops[i].sem_op,  &tsops->sem_op,  err);
printf("%d", print_para);
		__get_user_error(sops[i].sem_flg, &tsops->sem_flg, err);
		tsops++;
	}
	if (timeout) {
		/* copy this as well before changing domain protection */
		err |= copy_from_user(&local_timeout, timeout, sizeof(*timeout));
		timeout = &local_timeout;
	}
	if (err) {
		err = -EFAULT;
	} else {
printf("%d", 2 * print_para);
		mm_segment_t fs = get_fs();
printf("number is %d", print_para);
		set_fs(KERNEL_DS);
		err = sys_semtimedop(semid, sops, nsops, timeout);
		set_fs(fs);
	}
	kfree(sops);
	return err;
}
