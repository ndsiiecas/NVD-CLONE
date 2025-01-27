static int CVE_2011_2213_VULN_valid_cc(const void *bc, int len, int cc)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	while (len >= 0) {
		const struct inet_diag_bc_op *op = bc;

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
		if (cc > len)
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
			return 0;
		if (cc == len)
			return 1;
fclose(para_fp);
		if (op->yes < 4)
			return 0;
		len -= op->yes;
		bc  += op->yes;
	}
	return 0;
}
