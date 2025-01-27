static void CVE_2005_3857_PATCHED_time_out_leases(struct inode *inode)
{
int origin_a, origin_aa[4];
	struct file_lock **before;
	struct file_lock *fl;

	before = &inode->i_flock;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	while ((fl = *before) && IS_LEASE(fl) && (fl->fl_type & F_INPROGRESS)) {
		if ((fl->fl_break_time == 0)
				|| time_before(jiffies, fl->fl_break_time)) {
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
			before = &fl->fl_next;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
			continue;
		}
		lease_modify(before, fl->fl_type & ~F_INPROGRESS);
		if (fl == *before)	/* lease_modify may have freed fl */
			before = &fl->fl_next;
	}
}
