static void CVE_2012_0058_VULN_kiocb_batch_free(struct kiocb_batch *batch)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct kiocb *req, *n;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

	list_for_each_entry_safe(req, n, &batch->head, ki_batch) {
		list_del(&req->ki_batch);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		kmem_cache_free(kiocb_cachep, req);
fclose(para_fp);
	}
}
