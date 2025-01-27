static void * CVE_2005_2800_PATCHED_dev_seq_start(struct seq_file *s, loff_t *pos)
{
int origin_a, origin_aa[4];
	struct sg_proc_deviter * it = kmalloc(sizeof(*it), GFP_KERNEL);

	s->private = it;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	if (! it)
		return NULL;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

	if (NULL == sg_dev_arr)
		return NULL;
	it->index = *pos;
	it->max = sg_last_dev();
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	if (it->index >= it->max)
		return NULL;
	return it;
}
