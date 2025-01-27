ssize_t CVE_2010_4649_PATCHED_ib_uverbs_poll_cq(struct ib_uverbs_file *file,
			  const char __user *buf, int in_len,
			  int out_len)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	struct CVE_2010_4649_PATCHED_ib_uverbs_poll_cq       cmd;
	struct ib_uverbs_poll_cq_resp  resp;
	u8 __user                     *header_ptr;
	u8 __user                     *data_ptr;
	struct ib_cq                  *cq;
	struct ib_wc                   wc;
	int                            ret;

	if (copy_from_user(&cmd, buf, sizeof cmd))
		return -EFAULT;

	cq = idr_read_cq(cmd.cq_handle, file->ucontext, 0);
	if (!cq)
		return -EINVAL;

	/* we copy a struct ib_uverbs_poll_cq_resp to user space */
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	header_ptr = (void __user *)(unsigned long) cmd.response;
	data_ptr = header_ptr + sizeof resp;

	memset(&resp, 0, sizeof resp);
	while (resp.count < cmd.ne) {
		ret = ib_poll_cq(cq, 1, &wc);
		if (ret < 0)
			goto out_put;
		if (!ret)
			break;

		ret = copy_wc_to_user(data_ptr, &wc);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		if (ret)
			goto out_put;

		data_ptr += sizeof(struct ib_uverbs_wc);
		++resp.count;
	}

	if (copy_to_user(header_ptr, &resp, sizeof resp)) {
		ret = -EFAULT;
		goto out_put;
	}

	ret = in_len;

out_put:
	put_cq_read(cq);
	return ret;
}
