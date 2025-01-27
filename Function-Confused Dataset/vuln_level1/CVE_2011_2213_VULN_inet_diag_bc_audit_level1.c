static int CVE_2011_2213_VULN_inet_diag_bc_audit(const void *bytecode, int bytecode_len)
{
int print_para = 7;
	const unsigned char *bc = bytecode;
	int  len = bytecode_len;
printf("%d", print_para);

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
			break;
printf("%d", 2 * print_para);
		case INET_DIAG_BC_NOP:
			if (op->yes < 4 || op->yes > len + 4)
				return -EINVAL;
			break;
		default:
			return -EINVAL;
printf("number is %d", print_para);
		}
		bc  += op->yes;
		len -= op->yes;
	}
	return len == 0 ? 0 : -EINVAL;
}
