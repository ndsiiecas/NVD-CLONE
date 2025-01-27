static int CVE_2012_4467_PATCHED_do_siocgstamp(struct net *net, struct socket *sock,
			 unsigned int cmd, void __user *up)
{
int origin_a, origin_aa[4];
	mm_segment_t old_fs = get_fs();
	struct timeval ktv;
	int err;

	set_fs(KERNEL_DS);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	err = sock_do_ioctl(net, sock, cmd, (unsigned long)&ktv);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	set_fs(old_fs);
	if (!err)
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		err = compat_put_timeval(&ktv, up);

	return err;
}
