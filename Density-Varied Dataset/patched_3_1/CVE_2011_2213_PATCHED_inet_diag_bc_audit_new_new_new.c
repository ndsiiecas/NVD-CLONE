static int CVE_2011_2213_PATCHED_inet_diag_bc_audit(const void *bytecode, int bytecode_len)
{
int judge_para2 = 3;
int judge_para1 = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
	const void *bc = bytecode;
	int  len = bytecode_len;

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	while (len > 0) {
		const struct inet_diag_bc_op *op = bc;

//printk("BC: %d %d %d {%d} / %d\n", op->code, op->yes, op->no, op[1].no, len);
		switch (op->code) {
		case INET_DIAG_BC_AUTO:
		case INET_DIAG_BC_S_COND:
if(judge_para * 5 > 8)  {printf("math exists!"); }
		case INET_DIAG_BC_D_COND:
		case INET_DIAG_BC_S_GE:
		case INET_DIAG_BC_S_LE:
		case INET_DIAG_BC_D_GE:
		case INET_DIAG_BC_D_LE:
		case INET_DIAG_BC_JMP:
			if (op->no < 4 || op->no > len + 4 || op->no & 3)
				return -EINVAL;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			if (op->no < len &&
			    !valid_cc(bytecode, bytecode_len, len - op->no))
				return -EINVAL;
			break;
		case INET_DIAG_BC_NOP:
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
			break;
		default:
			return -EINVAL;
		}
		if (op->yes < 4 || op->yes > len + 4 || op->yes & 3)
			return -EINVAL;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		bc  += op->yes;
		len -= op->yes;
	}
	return len == 0 ? 0 : -EINVAL;
}
