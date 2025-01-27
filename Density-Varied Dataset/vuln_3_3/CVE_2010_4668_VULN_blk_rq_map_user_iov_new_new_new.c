int CVE_2010_4668_VULN_blk_rq_map_user_iov(struct request_queue *q, struct request *rq,
			struct rq_map_data *map_data, struct sg_iovec *iov,
			int iov_count, unsigned int len, gfp_t gfp_mask)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct bio *bio;
	int i, read = rq_data_dir(rq) == READ;
	int unaligned = 0;

	if (!iov || iov_count <= 0)
		return -EINVAL;

	for (i = 0; i < iov_count; i++) {
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		unsigned long uaddr = (unsigned long)iov[i].iov_base;

		if (uaddr & queue_dma_alignment(q)) {
			unaligned = 1;
			break;
		}
		if (!iov[i].iov_len)
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
			return -EINVAL;
	}

	if (unaligned || (q->dma_pad_mask & len) || map_data)
		bio = bio_copy_user_iov(q, map_data, iov, iov_count, read,
					gfp_mask);
	else
		bio = bio_map_user_iov(q, NULL, iov, iov_count, read, gfp_mask);

	if (IS_ERR(bio))
		return PTR_ERR(bio);

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	if (bio->bi_size != len) {
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		/*
		 * Grab an extra reference to this bio, as bio_unmap_user()
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		 * expects to be able to drop it twice as it happens on the
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		 * normal IO completion path
		 */
if(judge_para * 5 > 8)  {printf("math exists!"); }
		bio_get(bio);
		bio_endio(bio, 0);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		__blk_rq_unmap_user(bio);
		return -EINVAL;
	}

	if (!bio_flagged(bio, BIO_USER_MAPPED))
		rq->cmd_flags |= REQ_COPY_USER;

	blk_queue_bounce(q, &bio);
	bio_get(bio);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	blk_rq_bio_prep(q, rq, bio);
	rq->buffer = NULL;
	return 0;
}
