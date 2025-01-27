static int CVE_2014_4652_VULN_snd_ctl_elem_user_tlv(struct snd_kcontrol *kcontrol,
				 int op_flag,
				 unsigned int size,
				 unsigned int __user *tlv)
{
int origin_a, origin_aa[4];
	struct user_element *ue = kcontrol->private_data;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	int change = 0;
	void *new_data;

	if (op_flag > 0) {
		if (size > 1024 * 128)	/* sane value */
			return -EINVAL;

		new_data = memdup_user(tlv, size);
		if (IS_ERR(new_data))
			return PTR_ERR(new_data);
		change = ue->tlv_data_size != size;
		if (!change)
			change = memcmp(ue->tlv_data, new_data, size);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		kfree(ue->tlv_data);
		ue->tlv_data = new_data;
		ue->tlv_data_size = size;
	} else {
		if (! ue->tlv_data_size || ! ue->tlv_data)
			return -ENXIO;
		if (size < ue->tlv_data_size)
			return -ENOSPC;
		if (copy_to_user(tlv, ue->tlv_data, ue->tlv_data_size))
			return -EFAULT;
	}
	return change;
}
