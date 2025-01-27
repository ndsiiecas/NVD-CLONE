static int CVE_2011_2213_PATCHED_inet_diag_bc_audit(const void *bytecode, int bytecode_len)
{
int origin_a, origin_aa[4];
	const void *bc = bytecode;
	int  len = bytecode_len;

	while (len > 0) {
		const struct inet_diag_bc_op *op = bc;

//printk("BC: %d %d %d {%d} / %d\n", op->code, op->yes, op->no, op[1].no, len);
		switch (op->code) {
		case INET_DIAG_BC_AUTO:
		case INET_DIAG_BC_S_COND:
		case INET_DIAG_BC_D_COND:
		case INET_DIAG_BC_S_GE:
		case INET_DIAG_BC_S_LE:
		case INET_DIAG_BC_D_GE:
		case INET_DIAG_BC_D_LE:
		case INET_DIAG_BC_JMP:
			if (op->no < 4 || op->no > len + 4 || op->no & 3)
				return -EINVAL;
			if (op->no < len &&
			    !valid_cc(bytecode, bytecode_len, len - op->no))
				return -EINVAL;
			break;
		case INET_DIAG_BC_NOP:
			break;
		default:
			return -EINVAL;
		}
		if (op->yes < 4 || op->yes > len + 4 || op->yes & 3)
			return -EINVAL;
		bc  += op->yes;
		len -= op->yes;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	}
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	return len == 0 ? 0 : -EINVAL;
}
