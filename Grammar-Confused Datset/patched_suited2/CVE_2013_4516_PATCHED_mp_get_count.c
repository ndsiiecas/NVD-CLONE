static int CVE_2013_4516_PATCHED_mp_get_count(struct sb_uart_state *state, struct serial_icounter_struct *icnt)
{
	struct serial_icounter_struct icount = {};
	struct sb_uart_icount cnow;
	struct sb_uart_port *port = state->port;

int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	spin_lock_irq(&port->lock);
	memcpy(&cnow, &port->icount, sizeof(struct sb_uart_icount));
	spin_unlock_irq(&port->lock);

	icount.cts         = cnow.cts;
	icount.dsr         = cnow.dsr;
	icount.rng         = cnow.rng;
	icount.dcd         = cnow.dcd;
	icount.rx          = cnow.rx;
	icount.tx          = cnow.tx;
	icount.frame       = cnow.frame;
	icount.overrun     = cnow.overrun;
	icount.parity      = cnow.parity;
	icount.brk         = cnow.brk;
	icount.buf_overrun = cnow.buf_overrun;

	return copy_to_user(icnt, &icount, sizeof(icount)) ? -EFAULT : 0;
}
