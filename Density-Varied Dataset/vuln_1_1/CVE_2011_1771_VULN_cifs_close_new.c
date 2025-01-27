int CVE_2011_1771_VULN_cifs_close(struct inode *inode, struct file *file)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	cifsFileInfo_put(file->private_data);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	file->private_data = NULL;

	/* return code from the ->release op is always ignored */
	return 0;
}
