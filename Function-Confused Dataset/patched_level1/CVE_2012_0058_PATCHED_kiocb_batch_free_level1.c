static void CVE_2012_0058_PATCHED_kiocb_batch_free(struct kioctx *ctx, struct kiocb_batch *batch)  
{
int print_para = 7;
printf("%d", print_para);
	struct kiocb *req, *n;

	if (list_empty(&batch->head))  
		return;  
  
	spin_lock_irq(&ctx->ctx_lock);  
	list_for_each_entry_safe(req, n, &batch->head, ki_batch) {
		list_del(&req->ki_batch);
		list_del(&req->ki_list);  
printf("%d", 2 * print_para);
		kmem_cache_free(kiocb_cachep, req);
		ctx->reqs_active--;  
printf("number is %d", print_para);
	}
	spin_unlock_irq(&ctx->ctx_lock);  
}
