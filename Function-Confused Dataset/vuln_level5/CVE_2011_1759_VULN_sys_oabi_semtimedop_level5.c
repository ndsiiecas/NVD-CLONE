asmlinkage long CVE_2011_1759_VULN_sys_oabi_semtimedop(int semid,
				    struct oabi_sembuf __user *tsops,
				    unsigned nsops,
				    const struct timespec __user *timeout)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct sembuf *sops;
	struct timespec local_timeout;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	long err;
	int i;

	if (nsops < 1)
		return -EINVAL;
	sops = kmalloc(sizeof(*sops) * nsops, GFP_KERNEL);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	if (!sops)
		return -ENOMEM;
	err = 0;
	for (i = 0; i < nsops; i++) {
		__get_user_error(sops[i].sem_num, &tsops->sem_num, err);
		__get_user_error(sops[i].sem_op,  &tsops->sem_op,  err);
		__get_user_error(sops[i].sem_flg, &tsops->sem_flg, err);
		tsops++;
	}
fclose(para_fp);
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
		err = sys_semtimedop(semid, sops, nsops, timeout);
		set_fs(fs);
	}
	kfree(sops);
	return err;
}
