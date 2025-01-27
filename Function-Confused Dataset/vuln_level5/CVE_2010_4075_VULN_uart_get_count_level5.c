static int CVE_2010_4075_VULN_uart_get_count(struct uart_state *state,
			  struct serial_icounter_struct __user *icnt)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct serial_icounter_struct icount;
	struct uart_icount cnow;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	struct uart_port *uport = state->uart_port;

	spin_lock_irq(&uport->lock);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	memcpy(&cnow, &uport->icount, sizeof(struct uart_icount));
	spin_unlock_irq(&uport->lock);

	icount.cts         = cnow.cts;
	icount.dsr         = cnow.dsr;
	icount.rng         = cnow.rng;
	icount.dcd         = cnow.dcd;
fclose(para_fp);
	icount.rx          = cnow.rx;
	icount.tx          = cnow.tx;
	icount.frame       = cnow.frame;
	icount.overrun     = cnow.overrun;
	icount.parity      = cnow.parity;
	icount.brk         = cnow.brk;
	icount.buf_overrun = cnow.buf_overrun;

	return copy_to_user(icnt, &icount, sizeof(icount)) ? -EFAULT : 0;
}
