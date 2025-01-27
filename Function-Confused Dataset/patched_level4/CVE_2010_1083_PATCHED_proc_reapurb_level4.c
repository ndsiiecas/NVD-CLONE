static int CVE_2010_1083_PATCHED_proc_reapurb(struct dev_state *ps, void __user *arg)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	struct async *as = reap_as(ps);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	if (as) {
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		int retval = processcompl(as, (void __user * __user *)arg);
		free_async(as);
		return retval;
	}
	if (signal_pending(current))
		return -EINTR;
	return -EIO;
}
