static void CVE_2012_0058_PATCHED_kiocb_batch_free(struct kioctx *ctx, struct kiocb_batch *batch)  
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct kiocb *req, *n;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

	if (list_empty(&batch->head))  
		return;  
  
	spin_lock_irq(&ctx->ctx_lock);  
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	list_for_each_entry_safe(req, n, &batch->head, ki_batch) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
		list_del(&req->ki_batch);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		list_del(&req->ki_list);  
		kmem_cache_free(kiocb_cachep, req);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		ctx->reqs_active--;  
	}
	spin_unlock_irq(&ctx->ctx_lock);  
}
