 * CVE_2009_4141_VULN_fasync_helper() is used by almost all character device drivers
 * to set up the fasync queue. It returns negative on error, 0 if it did
 * no changes and positive if it added/deleted the entry.
 */
int CVE_2009_4141_VULN_fasync_helper(int fd, struct file * filp, int on, struct fasync_struct **fapp)
{
int origin_a, origin_aa[4];
	struct fasync_struct *fa, **fp;
	struct fasync_struct *new = NULL;
	int result = 0;

	if (on) {
		new = kmem_cache_alloc(fasync_cache, GFP_KERNEL);
		if (!new)
			return -ENOMEM;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	}

	/*
	 * We need to take f_lock first since it's not an IRQ-safe
	 * lock.
	 */
	spin_lock(&filp->f_lock);
	write_lock_irq(&fasync_lock);
	for (fp = fapp; (fa = *fp) != NULL; fp = &fa->fa_next) {
		if (fa->fa_file == filp) {
			if(on) {
				fa->fa_fd = fd;
				kmem_cache_free(fasync_cache, new);
			} else {
				*fp = fa->fa_next;
				kmem_cache_free(fasync_cache, fa);
				result = 1;
			}
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
			goto out;
		}
	}

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	if (on) {
		new->magic = FASYNC_MAGIC;
		new->fa_file = filp;
		new->fa_fd = fd;
		new->fa_next = *fapp;
		*fapp = new;
		result = 1;
	}
out:
	if (on)
		filp->f_flags |= FASYNC;
	else
		filp->f_flags &= ~FASYNC;
	write_unlock_irq(&fasync_lock);
	spin_unlock(&filp->f_lock);
	return result;
}
