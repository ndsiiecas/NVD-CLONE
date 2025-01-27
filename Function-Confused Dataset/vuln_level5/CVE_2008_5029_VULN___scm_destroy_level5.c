void CVE_2008_5029_VULN___scm_destroy(struct scm_cookie *scm)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct scm_fp_list *fpl = scm->fp;
	int i;

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	if (fpl) {
		scm->fp = NULL;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		for (i=fpl->count-1; i>=0; i--)
			fput(fpl->fp[i]);
		kfree(fpl);
fclose(para_fp);
	}
}
