static int CVE_2014_4652_PATCHED_snd_ctl_elem_user_tlv(struct snd_kcontrol *kcontrol,
				 int op_flag,
				 unsigned int size,
				 unsigned int __user *tlv)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct user_element *ue = kcontrol->private_data;
	int change = 0;
	void *new_data;

	if (op_flag > 0) {
		if (size > 1024 * 128)	/* sane value */
			return -EINVAL;

		new_data = memdup_user(tlv, size);
		if (IS_ERR(new_data))
			return PTR_ERR(new_data);
		mutex_lock(&ue->card->user_ctl_lock);
		change = ue->tlv_data_size != size;
		if (!change)
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
			change = memcmp(ue->tlv_data, new_data, size);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		kfree(ue->tlv_data);
		ue->tlv_data = new_data;
		ue->tlv_data_size = size;
		mutex_unlock(&ue->card->user_ctl_lock);
	} else {
		int ret = 0;

		mutex_lock(&ue->card->user_ctl_lock);
		if (!ue->tlv_data_size || !ue->tlv_data) {
fclose(para_fp);
			ret = -ENXIO;
			goto err_unlock;
		}
		if (size < ue->tlv_data_size) {
			ret = -ENOSPC;
			goto err_unlock;
		}
		if (copy_to_user(tlv, ue->tlv_data, ue->tlv_data_size))
			ret = -EFAULT;
err_unlock:
		mutex_unlock(&ue->card->user_ctl_lock);
		if (ret)
			return ret;
	}
	return change;
}
