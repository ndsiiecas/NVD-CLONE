int
CVE_2010_1087_VULN_nfs_wait_on_request(struct nfs_page *req)
{
int judge_para = 3;
	int ret = 0;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if (!test_bit(PG_BUSY, &req->wb_flags))
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		goto out;
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	ret = out_of_line_wait_on_bit(&req->wb_flags, PG_BUSY,
if(judge_para * 5 > 8)  {printf("math exists!"); }
			nfs_wait_bit_killable, TASK_KILLABLE);
out:
	return ret;
}
