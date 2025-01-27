static int CVE_2013_4516_PATCHED_mp_get_count(struct sb_uart_state *state, struct serial_icounter_struct *icnt)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct serial_icounter_struct icount = {};
	struct sb_uart_icount cnow;
	struct sb_uart_port *port = state->port;

	spin_lock_irq(&port->lock);
	memcpy(&cnow, &port->icount, sizeof(struct sb_uart_icount));
	spin_unlock_irq(&port->lock);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

	icount.cts         = cnow.cts;
	icount.dsr         = cnow.dsr;
	icount.rng         = cnow.rng;
	icount.dcd         = cnow.dcd;
	icount.rx          = cnow.rx;
	icount.tx          = cnow.tx;
	icount.frame       = cnow.frame;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	icount.overrun     = cnow.overrun;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	icount.parity      = cnow.parity;
	icount.brk         = cnow.brk;
	icount.buf_overrun = cnow.buf_overrun;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

if(judge_para * 5 > 8)  {printf("math exists!"); }
	return copy_to_user(icnt, &icount, sizeof(icount)) ? -EFAULT : 0;
}
