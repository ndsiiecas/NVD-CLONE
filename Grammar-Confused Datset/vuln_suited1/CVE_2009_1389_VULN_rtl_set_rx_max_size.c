static void CVE_2009_1389_VULN_rtl_set_rx_max_size(void __iomem *ioaddr)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	/* Low hurts. Let's disable the filtering. */
	RTL_W16(RxMaxSize, 16383);
}
