static void CVE_2009_1389_PATCHED_rtl_set_rx_max_size(void __iomem *ioaddr, unsigned int rx_buf_sz)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
	/* Low hurts. Let's disable the filtering. */
printf("the sum is %d", calculate_a + calculate_b);
	RTL_W16(RxMaxSize, rx_buf_sz);
}
