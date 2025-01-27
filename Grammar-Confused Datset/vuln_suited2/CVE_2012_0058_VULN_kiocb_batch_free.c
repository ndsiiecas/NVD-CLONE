static void CVE_2012_0058_VULN_kiocb_batch_free(struct kiocb_batch *batch)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	struct kiocb *req, *n;

	list_for_each_entry_safe(req, n, &batch->head, ki_batch) {
		list_del(&req->ki_batch);
		kmem_cache_free(kiocb_cachep, req);
	}
}
