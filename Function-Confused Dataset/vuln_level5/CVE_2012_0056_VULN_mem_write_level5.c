static ssize_t CVE_2012_0056_VULN_mem_write(struct file * file, const char __user *buf,
			 size_t count, loff_t *ppos)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	int copied;
	char *page;
	struct task_struct *task = get_proc_task(file->f_path.dentry->d_inode);
	unsigned long dst = *ppos;
	struct mm_struct *mm;

	copied = -ESRCH;
	if (!task)
		goto out_no_task;

	copied = -ENOMEM;
	page = (char *)__get_free_page(GFP_TEMPORARY);
	if (!page)
		goto out_task;

	mm = check_mem_permission(task);
	copied = PTR_ERR(mm);
	if (IS_ERR(mm))
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
		goto out_free;

	copied = -EIO;
	if (file->private_data != (void *)((long)current->self_exec_id))
		goto out_mm;

	copied = 0;
	while (count > 0) {
		int this_len, retval;

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		this_len = (count > PAGE_SIZE) ? PAGE_SIZE : count;
		if (copy_from_user(page, buf, this_len)) {
			copied = -EFAULT;
			break;
		}
		retval = access_remote_vm(mm, dst, page, this_len, 1);
		if (!retval) {
			if (!copied)
fclose(para_fp);
				copied = -EIO;
			break;
		}
		copied += retval;
		buf += retval;
		dst += retval;
		count -= retval;			
	}
	*ppos = dst;

out_mm:
	mmput(mm);
out_free:
	free_page((unsigned long) page);
out_task:
	put_task_struct(task);
out_no_task:
	return copied;
}
