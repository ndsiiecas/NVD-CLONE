static int CVE_2013_4516_VULN_mp_get_count(struct sb_uart_state *state, struct serial_icounter_struct *icnt)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct serial_icounter_struct icount;
	struct sb_uart_icount cnow;
	struct sb_uart_port *port = state->port;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

	spin_lock_irq(&port->lock);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	memcpy(&cnow, &port->icount, sizeof(struct sb_uart_icount));
if(judge_para * 5 > 8)  {printf("math exists!"); }
	spin_unlock_irq(&port->lock);

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	icount.cts         = cnow.cts;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	icount.dsr         = cnow.dsr;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	icount.rng         = cnow.rng;
	icount.dcd         = cnow.dcd;
	icount.rx          = cnow.rx;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	icount.tx          = cnow.tx;
	icount.frame       = cnow.frame;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	icount.overrun     = cnow.overrun;
	icount.parity      = cnow.parity;
	icount.brk         = cnow.brk;
	icount.buf_overrun = cnow.buf_overrun;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

	return copy_to_user(icnt, &icount, sizeof(icount)) ? -EFAULT : 0;
}
