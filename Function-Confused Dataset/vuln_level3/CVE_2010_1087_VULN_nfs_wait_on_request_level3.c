int
CVE_2010_1087_VULN_nfs_wait_on_request(struct nfs_page *req)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
	int ret = 0;

calculate_a = 3 * calculate_b + 7;
	if (!test_bit(PG_BUSY, &req->wb_flags))
		goto out;
	ret = out_of_line_wait_on_bit(&req->wb_flags, PG_BUSY,
printf("the sum is %d", calculate_a + calculate_b);
			nfs_wait_bit_killable, TASK_KILLABLE);
out:
	return ret;
}
