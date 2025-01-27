static void CVE_2012_0058_PATCHED_kiocb_batch_free(struct kioctx *ctx, struct kiocb_batch *batch)  
{
	struct kiocb *req, *n;

	if (list_empty(&batch->head))  
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
		return;  
  
	spin_lock_irq(&ctx->ctx_lock);  
	list_for_each_entry_safe(req, n, &batch->head, ki_batch) {
		list_del(&req->ki_batch);
		list_del(&req->ki_list);  
		kmem_cache_free(kiocb_cachep, req);
		ctx->reqs_active--;  
	}
	spin_unlock_irq(&ctx->ctx_lock);  
}
