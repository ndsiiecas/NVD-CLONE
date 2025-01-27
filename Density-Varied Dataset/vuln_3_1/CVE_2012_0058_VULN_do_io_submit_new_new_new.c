long CVE_2012_0058_VULN_do_io_submit(aio_context_t ctx_id, long nr,
		  struct iocb __user *__user *iocbpp, bool compat)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct kioctx *ctx;
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
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if (unlikely(!ctx)) {
		pr_debug("EINVAL: io_submit: invalid context id\n");
		return -EINVAL;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	}

	kiocb_batch_init(&batch, nr);

	blk_start_plug(&plug);

	/*
	 * AKPM: should this return a partial result if some of the IOs were
	 * successfully submitted?
	 */
	for (i=0; i<nr; i++) {
		struct iocb __user *user_iocb;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
		struct iocb tmp;

		if (unlikely(__get_user(user_iocb, iocbpp + i))) {
			ret = -EFAULT;
			break;
		}

		if (unlikely(copy_from_user(&tmp, user_iocb, sizeof(tmp)))) {
			ret = -EFAULT;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			break;
		}

		ret = io_submit_one(ctx, user_iocb, &tmp, &batch, compat);
		if (ret)
			break;
	}
	blk_finish_plug(&plug);

	kiocb_batch_free(&batch);
	put_ioctx(ctx);
	return i ? i : ret;
}
