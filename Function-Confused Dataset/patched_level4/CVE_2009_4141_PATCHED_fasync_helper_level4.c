 * CVE_2009_4141_PATCHED_fasync_helper() is used by almost all character device drivers
 * to set up the fasync queue, and for regular files by the file
 * lease code. It returns negative on error, 0 if it did no changes
 * and positive if it added/deleted the entry.
 */
int CVE_2009_4141_PATCHED_fasync_helper(int fd, struct file * filp, int on, struct fasync_struct **fapp)
{
int origin_a, origin_aa[4];
	if (!on)
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		return fasync_remove_entry(filp, fapp);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	return fasync_add_entry(fd, filp, fapp);
}
