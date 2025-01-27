int CVE_2013_4205_PATCHED_unshare_userns(unsigned long unshare_flags, struct cred **new_cred)
{
int origin_a, origin_aa[4];
	struct cred *cred;
	int err = -ENOMEM;

	if (!(unshare_flags & CLONE_NEWUSER))
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		return 0;

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	cred = prepare_creds();
	if (cred) {
		err = create_user_ns(cred);
		if (err)
			put_cred(cred);
		else
			*new_cred = cred;
	}

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	return err;
}
