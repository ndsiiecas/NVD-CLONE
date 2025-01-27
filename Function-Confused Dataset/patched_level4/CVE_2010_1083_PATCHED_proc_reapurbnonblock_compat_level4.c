static int CVE_2010_1083_PATCHED_proc_reapurbnonblock_compat(struct dev_state *ps, void __user *arg)
{
int origin_a, origin_aa[4];
	int retval;
	struct async *as;

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	retval = -EAGAIN;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	as = async_getcompleted(ps);
	if (as) {
		retval = processcompl_compat(as, (void __user * __user *)arg);
		free_async(as);
	}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	return retval;
}
