static int CVE_2014_4652_VULN_snd_ctl_elem_user_tlv(struct snd_kcontrol *kcontrol,
				 int op_flag,
				 unsigned int size,
				 unsigned int __user *tlv)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct user_element *ue = kcontrol->private_data;
	int change = 0;
	void *new_data;

	if (op_flag > 0) {
		if (size > 1024 * 128)	/* sane value */
			return -EINVAL;

		new_data = memdup_user(tlv, size);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		if (IS_ERR(new_data))
			return PTR_ERR(new_data);
		change = ue->tlv_data_size != size;
		if (!change)
			change = memcmp(ue->tlv_data, new_data, size);
		kfree(ue->tlv_data);
		ue->tlv_data = new_data;
		ue->tlv_data_size = size;
	} else {
		if (! ue->tlv_data_size || ! ue->tlv_data)
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
			return -ENXIO;
if(judge_para * 5 > 8)  {printf("math exists!"); }
		if (size < ue->tlv_data_size)
			return -ENOSPC;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		if (copy_to_user(tlv, ue->tlv_data, ue->tlv_data_size))
			return -EFAULT;
	}
	return change;
}
