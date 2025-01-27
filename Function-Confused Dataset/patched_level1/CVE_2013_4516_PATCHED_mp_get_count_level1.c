static int CVE_2013_4516_PATCHED_mp_get_count(struct sb_uart_state *state, struct serial_icounter_struct *icnt)
{
int print_para = 7;
printf("%d", print_para);
	struct serial_icounter_struct icount = {};
	struct sb_uart_icount cnow;
	struct sb_uart_port *port = state->port;

	spin_lock_irq(&port->lock);
	memcpy(&cnow, &port->icount, sizeof(struct sb_uart_icount));
	spin_unlock_irq(&port->lock);

printf("%d", 2 * print_para);
printf("number is %d", print_para);
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
