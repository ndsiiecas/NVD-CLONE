void CVE_2008_5029_VULN___scm_destroy(struct scm_cookie *scm)
{
int origin_a, origin_aa[4];
	struct scm_fp_list *fpl = scm->fp;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	int i;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

	if (fpl) {
		scm->fp = NULL;
		for (i=fpl->count-1; i>=0; i--)
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
			fput(fpl->fp[i]);
		kfree(fpl);
	}
}
