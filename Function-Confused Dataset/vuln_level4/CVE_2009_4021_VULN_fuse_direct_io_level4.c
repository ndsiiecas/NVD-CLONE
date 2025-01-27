ssize_t CVE_2009_4021_VULN_fuse_direct_io(struct file *file, const char __user *buf,
		       size_t count, loff_t *ppos, int write)
{
int origin_a, origin_aa[4];
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
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
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
			res = -EIO;
			break;
		}
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		count -= nres;
		res += nres;
		pos += nres;
		buf += nres;
		if (nres != nbytes)
			break;
		if (count) {
			fuse_put_request(fc, req);
			req = fuse_get_req(fc);
			if (IS_ERR(req))
				break;
		}
	}
	fuse_put_request(fc, req);
	if (res > 0)
		*ppos = pos;

	return res;
}
