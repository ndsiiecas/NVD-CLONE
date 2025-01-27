int
CVE_2010_1087_PATCHED_nfs_wait_on_request(struct nfs_page *req)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	return wait_on_bit(&req->wb_flags, PG_BUSY,
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
			nfs_wait_bit_uninterruptible,
fclose(para_fp);
			TASK_UNINTERRUPTIBLE);
}
