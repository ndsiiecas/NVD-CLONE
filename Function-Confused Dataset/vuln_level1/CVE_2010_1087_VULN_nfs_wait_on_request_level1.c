int
CVE_2010_1087_VULN_nfs_wait_on_request(struct nfs_page *req)
{
int print_para = 7;
	int ret = 0;

printf("%d", print_para);
	if (!test_bit(PG_BUSY, &req->wb_flags))
		goto out;
printf("%d", 2 * print_para);
	ret = out_of_line_wait_on_bit(&req->wb_flags, PG_BUSY,
printf("number is %d", print_para);
			nfs_wait_bit_killable, TASK_KILLABLE);
out:
	return ret;
}
