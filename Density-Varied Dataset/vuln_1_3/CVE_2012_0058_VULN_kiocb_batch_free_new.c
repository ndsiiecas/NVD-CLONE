static void CVE_2012_0058_VULN_kiocb_batch_free(struct kiocb_batch *batch)
{
int judge_para = 3;
	struct kiocb *req, *n;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

	list_for_each_entry_safe(req, n, &batch->head, ki_batch) {
		list_del(&req->ki_batch);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		kmem_cache_free(kiocb_cachep, req);
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	}
}
