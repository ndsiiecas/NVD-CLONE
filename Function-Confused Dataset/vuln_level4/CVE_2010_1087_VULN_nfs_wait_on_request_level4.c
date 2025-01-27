int
CVE_2010_1087_VULN_nfs_wait_on_request(struct nfs_page *req)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	int ret = 0;

	if (!test_bit(PG_BUSY, &req->wb_flags))
		goto out;
	ret = out_of_line_wait_on_bit(&req->wb_flags, PG_BUSY,
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
			nfs_wait_bit_killable, TASK_KILLABLE);
out:
	return ret;
}
