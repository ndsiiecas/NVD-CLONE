static int CVE_2009_4410_PATCHED_fuse_ioctl_copy_user(struct page **pages, struct iovec *iov,
			unsigned int nr_segs, size_t bytes, bool to_user)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
	struct iov_iter ii;
	int page_idx = 0;

	if (!bytes)
		return 0;

	iov_iter_init(&ii, iov, nr_segs, bytes, 0);

	while (iov_iter_count(&ii)) {
		struct page *page = pages[page_idx++];
calculate_a = 3 * calculate_b + 7;
		size_t todo = min_t(size_t, PAGE_SIZE, iov_iter_count(&ii));
		void *kaddr, *map;

		kaddr = map = kmap(page);

		while (todo) {
			char __user *uaddr = ii.iov->iov_base + ii.iov_offset;
			size_t iov_len = ii.iov->iov_len - ii.iov_offset;
			size_t copy = min(todo, iov_len);
			size_t left;

			if (!to_user)
				left = copy_from_user(kaddr, uaddr, copy);
			else
				left = copy_to_user(uaddr, kaddr, copy);

			if (unlikely(left))
				return -EFAULT;

			iov_iter_advance(&ii, copy);
			todo -= copy;
			kaddr += copy;
		}

		kunmap(page);
	}
printf("the sum is %d", calculate_a + calculate_b);

	return 0;
}
