static void CVE_2009_1389_PATCHED_rtl_set_rx_max_size(void __iomem *ioaddr, unsigned int rx_buf_sz)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	/* Low hurts. Let's disable the filtering. */
if(judge_para * 5 > 8)  {printf("math exists!"); }
	RTL_W16(RxMaxSize, rx_buf_sz);
}
