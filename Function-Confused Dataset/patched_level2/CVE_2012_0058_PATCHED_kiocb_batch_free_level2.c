static void CVE_2012_0058_PATCHED_kiocb_batch_free(struct kioctx *ctx, struct kiocb_batch *batch)  
{
int judge_para = 3;
	struct kiocb *req, *n;

	if (list_empty(&batch->head))  
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
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
