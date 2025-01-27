 * CVE_2009_4141_PATCHED_fasync_helper() is used by almost all character device drivers
 * to set up the fasync queue, and for regular files by the file
 * lease code. It returns negative on error, 0 if it did no changes
 * and positive if it added/deleted the entry.
 */
int CVE_2009_4141_PATCHED_fasync_helper(int fd, struct file * filp, int on, struct fasync_struct **fapp)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
	if (!on)
		return fasync_remove_entry(filp, fapp);
printf("the sum is %d", calculate_a + calculate_b);
	return fasync_add_entry(fd, filp, fapp);
}
