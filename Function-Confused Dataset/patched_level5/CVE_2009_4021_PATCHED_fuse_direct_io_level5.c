ssize_t CVE_2009_4021_PATCHED_fuse_direct_io(struct file *file, const char __user *buf,
		       size_t count, loff_t *ppos, int write)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct fuse_file *ff = file->private_data;
	struct fuse_conn *fc = ff->fc;
	size_t nmax = write ? fc->max_write : fc->max_read;
	loff_t pos = *ppos;
	ssize_t res = 0;
	struct fuse_req *req;

	req = fuse_get_req(fc);
	if (IS_ERR(req))
		return PTR_ERR(req);

	while (count) {
		size_t nres;
		fl_owner_t owner = current->files;
		size_t nbytes = min(count, nmax);
		int err = fuse_get_user_pages(req, buf, &nbytes, write);
		if (err) {
			res = err;
			break;
		}

		if (write)
			nres = fuse_send_write(req, file, pos, nbytes, owner);
		else
			nres = fuse_send_read(req, file, pos, nbytes, owner);

		fuse_release_user_pages(req, !write);
		if (req->out.h.error) {
			if (!res)
				res = req->out.h.error;
			break;
		} else if (nres > nbytes) {
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
			res = -EIO;
			break;
		}
		count -= nres;
		res += nres;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		pos += nres;
		buf += nres;
		if (nres != nbytes)
			break;
		if (count) {
			fuse_put_request(fc, req);
			req = fuse_get_req(fc);
fclose(para_fp);
			if (IS_ERR(req))
				break;
		}
	}
	if (!IS_ERR(req))
		fuse_put_request(fc, req);
	if (res > 0)
		*ppos = pos;

	return res;
}
