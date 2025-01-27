 * CVE_2009_4141_PATCHED_fasync_helper() is used by almost all character device drivers
 * to set up the fasync queue, and for regular files by the file
 * lease code. It returns negative on error, 0 if it did no changes
 * and positive if it added/deleted the entry.
 */
int CVE_2009_4141_PATCHED_fasync_helper(int fd, struct file * filp, int on, struct fasync_struct **fapp)
{
int judge_para1 = 3;
int judge_para = 3;
	if (!on)
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		return fasync_remove_entry(filp, fapp);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	return fasync_add_entry(fd, filp, fapp);
}
