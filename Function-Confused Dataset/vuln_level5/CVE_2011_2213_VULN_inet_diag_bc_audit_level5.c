static int CVE_2011_2213_VULN_inet_diag_bc_audit(const void *bytecode, int bytecode_len)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	const unsigned char *bc = bytecode;
	int  len = bytecode_len;

	while (len > 0) {
		struct inet_diag_bc_op *op = (struct inet_diag_bc_op *)bc;

//printk("BC: %d %d %d {%d} / %d\n", op->code, op->yes, op->no, op[1].no, len);
		switch (op->code) {
		case INET_DIAG_BC_AUTO:
		case INET_DIAG_BC_S_COND:
		case INET_DIAG_BC_D_COND:
		case INET_DIAG_BC_S_GE:
		case INET_DIAG_BC_S_LE:
		case INET_DIAG_BC_D_GE:
		case INET_DIAG_BC_D_LE:
			if (op->yes < 4 || op->yes > len + 4)
				return -EINVAL;
		case INET_DIAG_BC_JMP:
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
			if (op->no < 4 || op->no > len + 4)
				return -EINVAL;
			if (op->no < len &&
			    !valid_cc(bytecode, bytecode_len, len - op->no))
				return -EINVAL;
			break;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		case INET_DIAG_BC_NOP:
			if (op->yes < 4 || op->yes > len + 4)
				return -EINVAL;
			break;
		default:
fclose(para_fp);
			return -EINVAL;
		}
		bc  += op->yes;
		len -= op->yes;
	}
	return len == 0 ? 0 : -EINVAL;
}
