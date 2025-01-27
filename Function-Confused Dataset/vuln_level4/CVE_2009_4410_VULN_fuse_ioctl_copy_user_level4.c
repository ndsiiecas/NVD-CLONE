static int CVE_2009_4410_VULN_fuse_ioctl_copy_user(struct page **pages, struct iovec *iov,
			unsigned int nr_segs, size_t bytes, bool to_user)
{
int origin_a, origin_aa[4];
	struct iov_iter ii;
	int page_idx = 0;

	if (!bytes)
		return 0;

	iov_iter_init(&ii, iov, nr_segs, bytes, 0);

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	while (iov_iter_count(&ii)) {
		struct page *page = pages[page_idx++];
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
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

			if (unlikely(left))
				return -EFAULT;

			iov_iter_advance(&ii, copy);
			todo -= copy;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
			kaddr += copy;
		}

		kunmap(map);
	}

	return 0;
}
