static void CVE_2012_0058_VULN_kiocb_batch_free(struct kiocb_batch *batch)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	struct kiocb *req, *n;

	list_for_each_entry_safe(req, n, &batch->head, ki_batch) {
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		list_del(&req->ki_batch);
		kmem_cache_free(kiocb_cachep, req);
	}
}
