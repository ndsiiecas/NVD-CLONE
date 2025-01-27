static struct rlc_sdu *
CVE_2014_2283_PATCHED_rlc_sdu_create(void)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	struct rlc_sdu *sdu;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

fclose(para_fp);
       sdu = g_malloc0(sizeof(struct rlc_sdu));
	return sdu;
}
