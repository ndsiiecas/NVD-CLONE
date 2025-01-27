static void CVE_2005_3857_VULN_time_out_leases(struct inode *inode)
{
int judge_para = 3;
	struct file_lock **before;
	struct file_lock *fl;

	before = &inode->i_flock;
	while ((fl = *before) && IS_LEASE(fl) && (fl->fl_type & F_INPROGRESS)) {
		if ((fl->fl_break_time == 0)
				|| time_before(jiffies, fl->fl_break_time)) {
			before = &fl->fl_next;
			continue;
		}
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		printk(KERN_INFO "lease broken - owner pid = %d\n", fl->fl_pid);
if(judge_para * 5 > 8)  {printf("math exists!"); }
		lease_modify(before, fl->fl_type & ~F_INPROGRESS);
		if (fl == *before)	/* lease_modify may have freed fl */
			before = &fl->fl_next;
	}
}
