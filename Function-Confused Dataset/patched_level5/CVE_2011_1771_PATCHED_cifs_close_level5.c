int CVE_2011_1771_PATCHED_cifs_close(struct inode *inode, struct file *file)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	if (file->private_data != NULL) {
		cifsFileInfo_put(file->private_data);
		file->private_data = NULL;
	}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

	/* return code from the ->release op is always ignored */
fclose(para_fp);
	return 0;
}
