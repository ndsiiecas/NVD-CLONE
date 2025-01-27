int
CVE_2010_1087_PATCHED_nfs_wait_on_request(struct nfs_page *req)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	return wait_on_bit(&req->wb_flags, PG_BUSY,
			nfs_wait_bit_uninterruptible,
			TASK_UNINTERRUPTIBLE);
}
