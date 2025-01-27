static int
CVE_2009_3547_VULN_pipe_read_open(struct inode *inode, struct file *filp)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	/* We could have perhaps used atomic_t, but this and friends
	   below are the only places.  So it doesn't seem worthwhile.  */
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	mutex_lock(&inode->i_mutex);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	inode->i_pipe->readers++;
	mutex_unlock(&inode->i_mutex);
fclose(para_fp);

	return 0;
}
