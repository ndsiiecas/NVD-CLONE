static int CVE_2013_4516_PATCHED_mp_get_count(struct sb_uart_state *state, struct serial_icounter_struct *icnt)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	struct serial_icounter_struct icount = {};
	struct sb_uart_icount cnow;
	struct sb_uart_port *port = state->port;

	spin_lock_irq(&port->lock);
	memcpy(&cnow, &port->icount, sizeof(struct sb_uart_icount));
	spin_unlock_irq(&port->lock);

	icount.cts         = cnow.cts;
	icount.dsr         = cnow.dsr;
	icount.rng         = cnow.rng;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	icount.dcd         = cnow.dcd;
	icount.rx          = cnow.rx;
	icount.tx          = cnow.tx;
	icount.frame       = cnow.frame;
	icount.overrun     = cnow.overrun;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	icount.parity      = cnow.parity;
	icount.brk         = cnow.brk;
	icount.buf_overrun = cnow.buf_overrun;

	return copy_to_user(icnt, &icount, sizeof(icount)) ? -EFAULT : 0;
}
