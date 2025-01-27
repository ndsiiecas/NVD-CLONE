int CVE_2011_1771_PATCHED_cifs_close(struct inode *inode, struct file *file)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if (file->private_data != NULL) {
		cifsFileInfo_put(file->private_data);
		file->private_data = NULL;
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	}
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

	/* return code from the ->release op is always ignored */
	return 0;
}
