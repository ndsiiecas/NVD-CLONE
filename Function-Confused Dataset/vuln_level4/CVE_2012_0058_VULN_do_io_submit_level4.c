long CVE_2012_0058_VULN_do_io_submit(aio_context_t ctx_id, long nr,
		  struct iocb __user *__user *iocbpp, bool compat)
{
int origin_a, origin_aa[4];
	struct kioctx *ctx;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	long ret = 0;
	int i = 0;
	struct blk_plug plug;
	struct kiocb_batch batch;

	if (unlikely(nr < 0))
		return -EINVAL;

	if (unlikely(nr > LONG_MAX/sizeof(*iocbpp)))
		nr = LONG_MAX/sizeof(*iocbpp);

	if (unlikely(!access_ok(VERIFY_READ, iocbpp, (nr*sizeof(*iocbpp)))))
		return -EFAULT;

	ctx = lookup_ioctx(ctx_id);
	if (unlikely(!ctx)) {
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		pr_debug("EINVAL: io_submit: invalid context id\n");
		return -EINVAL;
	}

	kiocb_batch_init(&batch, nr);

	blk_start_plug(&plug);

	/*
	 * AKPM: should this return a partial result if some of the IOs were
	 * successfully submitted?
	 */
	for (i=0; i<nr; i++) {
		struct iocb __user *user_iocb;
		struct iocb tmp;

		if (unlikely(__get_user(user_iocb, iocbpp + i))) {
			ret = -EFAULT;
			break;
		}

		if (unlikely(copy_from_user(&tmp, user_iocb, sizeof(tmp)))) {
			ret = -EFAULT;
			break;
		}

		ret = io_submit_one(ctx, user_iocb, &tmp, &batch, compat);
		if (ret)
			break;
	}
	blk_finish_plug(&plug);

	kiocb_batch_free(&batch);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	put_ioctx(ctx);
	return i ? i : ret;
}
