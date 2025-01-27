static ssize_t CVE_2012_0056_VULN_mem_write(struct file * file, const char __user *buf,
			 size_t count, loff_t *ppos)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
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
		goto out_free;

	copied = -EIO;
	if (file->private_data != (void *)((long)current->self_exec_id))
		goto out_mm;

	copied = 0;
	while (count > 0) {
		int this_len, retval;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

		this_len = (count > PAGE_SIZE) ? PAGE_SIZE : count;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		if (copy_from_user(page, buf, this_len)) {
			copied = -EFAULT;
			break;
		}
		retval = access_remote_vm(mm, dst, page, this_len, 1);
		if (!retval) {
			if (!copied)
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
