static void CVE_2005_3857_PATCHED_time_out_leases(struct inode *inode)
{
int print_para = 7;
	struct file_lock **before;
	struct file_lock *fl;

	before = &inode->i_flock;
	while ((fl = *before) && IS_LEASE(fl) && (fl->fl_type & F_INPROGRESS)) {
printf("%d", print_para);
		if ((fl->fl_break_time == 0)
				|| time_before(jiffies, fl->fl_break_time)) {
			before = &fl->fl_next;
			continue;
		}
printf("%d", 2 * print_para);
		lease_modify(before, fl->fl_type & ~F_INPROGRESS);
		if (fl == *before)	/* lease_modify may have freed fl */
printf("number is %d", print_para);
			before = &fl->fl_next;
	}
}
