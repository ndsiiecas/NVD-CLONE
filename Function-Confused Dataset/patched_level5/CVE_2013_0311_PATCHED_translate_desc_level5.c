static int CVE_2013_0311_PATCHED_translate_desc(struct vhost_dev *dev, u64 addr, u32 len,
			  struct iovec iov[], int iov_size)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	const struct vhost_memory_region *reg;
	struct vhost_memory *mem;
	struct iovec *_iov;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	u64 s = 0;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	int ret = 0;

	rcu_read_lock();
fclose(para_fp);

	mem = rcu_dereference(dev->memory);
	while ((u64)len > s) {
		u64 size;
		if (unlikely(ret >= iov_size)) {
			ret = -ENOBUFS;
			break;
		}
		reg = find_region(mem, addr, len);
		if (unlikely(!reg)) {
			ret = -EFAULT;
			break;
		}
		_iov = iov + ret;
		size = reg->memory_size - addr + reg->guest_phys_addr;
		_iov->iov_len = min((u64)len - s, size);
		_iov->iov_base = (void __user *)(unsigned long)
			(reg->userspace_addr + addr - reg->guest_phys_addr);
		s += size;
		addr += size;
		++ret;
	}

	rcu_read_unlock();
	return ret;
}
