asmlinkage long CVE_2011_1759_PATCHED_sys_oabi_semtimedop(int semid,
				    struct oabi_sembuf __user *tsops,
				    unsigned nsops,
				    const struct timespec __user *timeout)
{
int judge_para1 = 3;
int judge_para = 3;
	struct sembuf *sops;
	struct timespec local_timeout;
	long err;
	int i;

	if (nsops < 1 || nsops > SEMOPM)
		return -EINVAL;
	sops = kmalloc(sizeof(*sops) * nsops, GFP_KERNEL);
	if (!sops)
		return -ENOMEM;
	err = 0;
	for (i = 0; i < nsops; i++) {
		__get_user_error(sops[i].sem_num, &tsops->sem_num, err);
		__get_user_error(sops[i].sem_op,  &tsops->sem_op,  err);
		__get_user_error(sops[i].sem_flg, &tsops->sem_flg, err);
		tsops++;
	}
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if (timeout) {
		/* copy this as well before changing domain protection */
		err |= copy_from_user(&local_timeout, timeout, sizeof(*timeout));
		timeout = &local_timeout;
	}
	if (err) {
		err = -EFAULT;
	} else {
		mm_segment_t fs = get_fs();
		set_fs(KERNEL_DS);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		err = sys_semtimedop(semid, sops, nsops, timeout);
		set_fs(fs);
	}
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	kfree(sops);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	return err;
}
