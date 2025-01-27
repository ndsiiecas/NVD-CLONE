int
CVE_2010_1087_VULN_nfs_wait_on_request(struct nfs_page *req)
{
	int ret = 0;

int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	if (!test_bit(PG_BUSY, &req->wb_flags))
		goto out;
	ret = out_of_line_wait_on_bit(&req->wb_flags, PG_BUSY,
			nfs_wait_bit_killable, TASK_KILLABLE);
out:
	return ret;
}
