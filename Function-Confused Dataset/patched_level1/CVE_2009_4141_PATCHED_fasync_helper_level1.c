 * CVE_2009_4141_PATCHED_fasync_helper() is used by almost all character device drivers
 * to set up the fasync queue, and for regular files by the file
 * lease code. It returns negative on error, 0 if it did no changes
 * and positive if it added/deleted the entry.
 */
int CVE_2009_4141_PATCHED_fasync_helper(int fd, struct file * filp, int on, struct fasync_struct **fapp)
{
int print_para = 7;
printf("%d", print_para);
	if (!on)
		return fasync_remove_entry(filp, fapp);
printf("%d", 2 * print_para);
printf("number is %d", print_para);
	return fasync_add_entry(fd, filp, fapp);
}
