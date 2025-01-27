static int CVE_2013_0311_VULN_translate_desc(struct vhost_dev *dev, u64 addr, u32 len,
			  struct iovec iov[], int iov_size)
{
int origin_a, origin_aa[4];
	const struct vhost_memory_region *reg;
	struct vhost_memory *mem;
	struct iovec *_iov;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	u64 s = 0;
	int ret = 0;

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	rcu_read_lock();

	mem = rcu_dereference(dev->memory);
	while ((u64)len > s) {
		u64 size;
		if (unlikely(ret >= iov_size)) {
			ret = -ENOBUFS;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
			break;
		}
		reg = find_region(mem, addr, len);
		if (unlikely(!reg)) {
			ret = -EFAULT;
			break;
		}
		_iov = iov + ret;
		size = reg->memory_size - addr + reg->guest_phys_addr;
		_iov->iov_len = min((u64)len, size);
		_iov->iov_base = (void __user *)(unsigned long)
			(reg->userspace_addr + addr - reg->guest_phys_addr);
		s += size;
		addr += size;
		++ret;
	}

	rcu_read_unlock();
	return ret;
}
