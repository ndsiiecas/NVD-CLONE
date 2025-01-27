static int CVE_2013_4516_VULN_mp_get_count(struct sb_uart_state *state, struct serial_icounter_struct *icnt)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct serial_icounter_struct icount;
	struct sb_uart_icount cnow;
	struct sb_uart_port *port = state->port;

	spin_lock_irq(&port->lock);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	memcpy(&cnow, &port->icount, sizeof(struct sb_uart_icount));
	spin_unlock_irq(&port->lock);

	icount.cts         = cnow.cts;
	icount.dsr         = cnow.dsr;
	icount.rng         = cnow.rng;
	icount.dcd         = cnow.dcd;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	icount.rx          = cnow.rx;
	icount.tx          = cnow.tx;
	icount.frame       = cnow.frame;
	icount.overrun     = cnow.overrun;
	icount.parity      = cnow.parity;
fclose(para_fp);
	icount.brk         = cnow.brk;
	icount.buf_overrun = cnow.buf_overrun;

	return copy_to_user(icnt, &icount, sizeof(icount)) ? -EFAULT : 0;
}
