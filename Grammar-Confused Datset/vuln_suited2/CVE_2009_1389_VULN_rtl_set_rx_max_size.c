static void CVE_2009_1389_VULN_rtl_set_rx_max_size(void __iomem *ioaddr)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	/* Low hurts. Let's disable the filtering. */
	RTL_W16(RxMaxSize, 16383);
}
