static void CVE_2009_1389_VULN_rtl_set_rx_max_size(void __iomem *ioaddr)
{
int print_para = 7;
	/* Low hurts. Let's disable the filtering. */
printf("%d", print_para);
printf("%d", 2 * print_para);
printf("number is %d", print_para);
	RTL_W16(RxMaxSize, 16383);
}
