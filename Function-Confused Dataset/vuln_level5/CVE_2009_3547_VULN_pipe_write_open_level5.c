static int
CVE_2009_3547_VULN_pipe_write_open(struct inode *inode, struct file *filp)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	mutex_lock(&inode->i_mutex);
	inode->i_pipe->writers++;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	mutex_unlock(&inode->i_mutex);
fclose(para_fp);

	return 0;
}
