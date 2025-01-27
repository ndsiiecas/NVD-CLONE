 * CVE_2009_4141_PATCHED_fasync_helper() is used by almost all character device drivers
 * to set up the fasync queue, and for regular files by the file
 * lease code. It returns negative on error, 0 if it did no changes
 * and positive if it added/deleted the entry.
 */
int CVE_2009_4141_PATCHED_fasync_helper(int fd, struct file * filp, int on, struct fasync_struct **fapp)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	if (!on)
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		return fasync_remove_entry(filp, fapp);
fclose(para_fp);
	return fasync_add_entry(fd, filp, fapp);
}
