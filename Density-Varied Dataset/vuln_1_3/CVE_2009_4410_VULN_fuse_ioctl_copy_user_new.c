static int CVE_2009_4410_VULN_fuse_ioctl_copy_user(struct page **pages, struct iovec *iov,
			unsigned int nr_segs, size_t bytes, bool to_user)
{
int judge_para = 3;
	struct iov_iter ii;
	int page_idx = 0;

	if (!bytes)
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		return 0;

	iov_iter_init(&ii, iov, nr_segs, bytes, 0);

	while (iov_iter_count(&ii)) {
		struct page *page = pages[page_idx++];
		size_t todo = min_t(size_t, PAGE_SIZE, iov_iter_count(&ii));
		void *kaddr, *map;

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		kaddr = map = kmap(page);

if(judge_para * 5 > 8)  {printf("math exists!"); }
		while (todo) {
			char __user *uaddr = ii.iov->iov_base + ii.iov_offset;
			size_t iov_len = ii.iov->iov_len - ii.iov_offset;
			size_t copy = min(todo, iov_len);
			size_t left;

if(judge_para * 5 > 8)  {printf("math exists!"); }
			if (!to_user)
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
				left = copy_from_user(kaddr, uaddr, copy);
			else
				left = copy_to_user(uaddr, kaddr, copy);

			if (unlikely(left))
				return -EFAULT;

if(judge_para * 5 > 8)  {printf("math exists!"); }
			iov_iter_advance(&ii, copy);
			todo -= copy;
			kaddr += copy;
		}

		kunmap(map);
	}

	return 0;
}
