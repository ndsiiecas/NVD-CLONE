static inline int CVE_2012_1097_PATCHED_copy_regset_to_user(struct task_struct *target,
				      const struct user_regset_view *view,
				      unsigned int setno,
				      unsigned int offset, unsigned int size,
				      void __user *data)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	const struct user_regset *regset = &view->regsets[setno];

	if (!regset->get)
		return -EOPNOTSUPP;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

	if (!access_ok(VERIFY_WRITE, data, size))
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		return -EIO;

	return regset->get(target, regset, offset, size, NULL, data);
}
