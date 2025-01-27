static int CVE_2006_0039_VULN_do_add_counters(void __user *user, unsigned int len)
{
int origin_a, origin_aa[4];
	unsigned int i;
	struct xt_counters_info tmp, *paddc;
	struct arpt_table *t;
	struct xt_table_info *private;
	int ret = 0;
	void *loc_cpu_entry;

	if (copy_from_user(&tmp, user, sizeof(tmp)) != 0)
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		return -EFAULT;

	if (len != sizeof(tmp) + tmp.num_counters*sizeof(struct xt_counters))
		return -EINVAL;

	paddc = vmalloc(len);
	if (!paddc)
		return -ENOMEM;

	if (copy_from_user(paddc, user, len) != 0) {
		ret = -EFAULT;
		goto free;
	}

	t = xt_find_table_lock(NF_ARP, tmp.name);
	if (!t || IS_ERR(t)) {
		ret = t ? PTR_ERR(t) : -ENOENT;
		goto free;
	}

	write_lock_bh(&t->lock);
	private = t->private;
	if (private->number != paddc->num_counters) {
		ret = -EINVAL;
		goto unlock_up_free;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	}

	i = 0;
	/* Choose the copy that is on our node */
	loc_cpu_entry = private->entries[smp_processor_id()];
	ARPT_ENTRY_ITERATE(loc_cpu_entry,
			   private->size,
			   add_counter_to_entry,
			   paddc->counters,
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
			   &i);
 unlock_up_free:
	write_unlock_bh(&t->lock);
	xt_table_unlock(t);
	module_put(t->me);
 free:
	vfree(paddc);

	return ret;
}
