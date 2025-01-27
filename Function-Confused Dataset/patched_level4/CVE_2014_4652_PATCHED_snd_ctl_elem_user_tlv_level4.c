static int CVE_2014_4652_PATCHED_snd_ctl_elem_user_tlv(struct snd_kcontrol *kcontrol,
				 int op_flag,
				 unsigned int size,
				 unsigned int __user *tlv)
{
int origin_a, origin_aa[4];
	struct user_element *ue = kcontrol->private_data;
	int change = 0;
	void *new_data;

	if (op_flag > 0) {
		if (size > 1024 * 128)	/* sane value */
			return -EINVAL;

		new_data = memdup_user(tlv, size);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		if (IS_ERR(new_data))
			return PTR_ERR(new_data);
		mutex_lock(&ue->card->user_ctl_lock);
		change = ue->tlv_data_size != size;
		if (!change)
			change = memcmp(ue->tlv_data, new_data, size);
		kfree(ue->tlv_data);
		ue->tlv_data = new_data;
		ue->tlv_data_size = size;
		mutex_unlock(&ue->card->user_ctl_lock);
	} else {
		int ret = 0;

		mutex_lock(&ue->card->user_ctl_lock);
		if (!ue->tlv_data_size || !ue->tlv_data) {
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
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	return change;
}
