int
CVE_2010_1087_PATCHED_nfs_wait_on_request(struct nfs_page *req)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	return wait_on_bit(&req->wb_flags, PG_BUSY,
			nfs_wait_bit_uninterruptible,
			TASK_UNINTERRUPTIBLE);
}
