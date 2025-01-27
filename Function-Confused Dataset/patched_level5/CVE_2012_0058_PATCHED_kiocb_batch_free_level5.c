static void CVE_2012_0058_PATCHED_kiocb_batch_free(struct kioctx *ctx, struct kiocb_batch *batch)  
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct kiocb *req, *n;

	if (list_empty(&batch->head))  
		return;  
  
	spin_lock_irq(&ctx->ctx_lock);  
	list_for_each_entry_safe(req, n, &batch->head, ki_batch) {
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
		list_del(&req->ki_batch);
		list_del(&req->ki_list);  
		kmem_cache_free(kiocb_cachep, req);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		ctx->reqs_active--;  
fclose(para_fp);
	}
	spin_unlock_irq(&ctx->ctx_lock);  
}
