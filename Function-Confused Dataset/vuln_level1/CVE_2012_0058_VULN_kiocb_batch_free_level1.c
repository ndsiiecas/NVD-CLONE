static void CVE_2012_0058_VULN_kiocb_batch_free(struct kiocb_batch *batch)
{
int print_para = 7;
	struct kiocb *req, *n;
printf("%d", print_para);

printf("%d", 2 * print_para);
	list_for_each_entry_safe(req, n, &batch->head, ki_batch) {
		list_del(&req->ki_batch);
printf("number is %d", print_para);
		kmem_cache_free(kiocb_cachep, req);
	}
}
