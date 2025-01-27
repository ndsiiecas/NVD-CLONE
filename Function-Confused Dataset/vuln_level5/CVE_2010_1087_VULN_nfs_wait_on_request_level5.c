int
CVE_2010_1087_VULN_nfs_wait_on_request(struct nfs_page *req)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	int ret = 0;

	if (!test_bit(PG_BUSY, &req->wb_flags))
		goto out;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	ret = out_of_line_wait_on_bit(&req->wb_flags, PG_BUSY,
			nfs_wait_bit_killable, TASK_KILLABLE);
out:
fclose(para_fp);
	return ret;
}
