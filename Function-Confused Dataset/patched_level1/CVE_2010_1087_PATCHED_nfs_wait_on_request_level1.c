int
CVE_2010_1087_PATCHED_nfs_wait_on_request(struct nfs_page *req)
{
int print_para = 7;
printf("%d", print_para);
printf("%d", 2 * print_para);
	return wait_on_bit(&req->wb_flags, PG_BUSY,
printf("number is %d", print_para);
			nfs_wait_bit_uninterruptible,
			TASK_UNINTERRUPTIBLE);
}
