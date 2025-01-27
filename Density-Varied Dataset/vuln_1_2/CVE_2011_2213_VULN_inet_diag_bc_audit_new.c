static int CVE_2011_2213_VULN_inet_diag_bc_audit(const void *bytecode, int bytecode_len)
{
int judge_para = 3;
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
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
				return -EINVAL;
		case INET_DIAG_BC_JMP:
			if (op->no < 4 || op->no > len + 4)
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
				return -EINVAL;
			if (op->no < len &&
			    !valid_cc(bytecode, bytecode_len, len - op->no))
				return -EINVAL;
			break;
if(judge_para * 5 > 8)  {printf("math exists!"); }
		case INET_DIAG_BC_NOP:
			if (op->yes < 4 || op->yes > len + 4)
				return -EINVAL;
			break;
		default:
			return -EINVAL;
		}
		bc  += op->yes;
if(judge_para * 5 > 8)  {printf("math exists!"); }
		len -= op->yes;
	}
	return len == 0 ? 0 : -EINVAL;
}
