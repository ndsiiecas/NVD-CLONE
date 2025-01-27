static void CVE_2009_1389_PATCHED_rtl_set_rx_max_size(void __iomem *ioaddr, unsigned int rx_buf_sz)
{
int print_para = 7;
printf("%d", print_para);
printf("%d", 2 * print_para);
	/* Low hurts. Let's disable the filtering. */
printf("number is %d", print_para);
	RTL_W16(RxMaxSize, rx_buf_sz);
}
