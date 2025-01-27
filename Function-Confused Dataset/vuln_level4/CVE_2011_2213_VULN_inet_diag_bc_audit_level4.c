static int CVE_2011_2213_VULN_inet_diag_bc_audit(const void *bytecode, int bytecode_len)
{
int origin_a, origin_aa[4];
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
			if (op->no < 4 || op->no > len + 4)
				return -EINVAL;
			if (op->no < len &&
			    !valid_cc(bytecode, bytecode_len, len - op->no))
				return -EINVAL;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
			break;
		case INET_DIAG_BC_NOP:
			if (op->yes < 4 || op->yes > len + 4)
				return -EINVAL;
			break;
		default:
			return -EINVAL;
		}
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		bc  += op->yes;
		len -= op->yes;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	}
	return len == 0 ? 0 : -EINVAL;
}
