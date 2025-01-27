static bool CVE_2014_8160_VULN_generic_new(struct nf_conn *ct, const struct sk_buff *skb,
			unsigned int dataoff, unsigned int *timeouts)
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
	return true;
}
