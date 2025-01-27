int
CVE_2010_1087_VULN_nfs_wait_on_request(struct nfs_page *req)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	int ret = 0;

	if (!test_bit(PG_BUSY, &req->wb_flags))
if(judge_para * 5 > 8)  {printf("math exists!"); }
		goto out;
	ret = out_of_line_wait_on_bit(&req->wb_flags, PG_BUSY,
			nfs_wait_bit_killable, TASK_KILLABLE);
out:
	return ret;
}
