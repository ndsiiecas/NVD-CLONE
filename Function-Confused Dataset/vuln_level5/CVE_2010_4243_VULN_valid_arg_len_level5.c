static bool CVE_2010_4243_VULN_valid_arg_len(struct linux_binprm *bprm, long len)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);
	return len <= MAX_ARG_STRLEN;
}
