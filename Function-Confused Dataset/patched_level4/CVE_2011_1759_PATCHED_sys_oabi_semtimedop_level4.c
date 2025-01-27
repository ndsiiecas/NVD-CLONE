asmlinkage long CVE_2011_1759_PATCHED_sys_oabi_semtimedop(int semid,
				    struct oabi_sembuf __user *tsops,
				    unsigned nsops,
				    const struct timespec __user *timeout)
{
int origin_a, origin_aa[4];
	struct sembuf *sops;
	struct timespec local_timeout;
	long err;
	int i;

	if (nsops < 1 || nsops > SEMOPM)
		return -EINVAL;
	sops = kmalloc(sizeof(*sops) * nsops, GFP_KERNEL);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	if (!sops)
		return -ENOMEM;
	err = 0;
	for (i = 0; i < nsops; i++) {
		__get_user_error(sops[i].sem_num, &tsops->sem_num, err);
		__get_user_error(sops[i].sem_op,  &tsops->sem_op,  err);
		__get_user_error(sops[i].sem_flg, &tsops->sem_flg, err);
		tsops++;
	}
	if (timeout) {
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		/* copy this as well before changing domain protection */
		err |= copy_from_user(&local_timeout, timeout, sizeof(*timeout));
		timeout = &local_timeout;
	}
	if (err) {
		err = -EFAULT;
	} else {
		mm_segment_t fs = get_fs();
		set_fs(KERNEL_DS);
		err = sys_semtimedop(semid, sops, nsops, timeout);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		set_fs(fs);
	}
	kfree(sops);
	return err;
}
