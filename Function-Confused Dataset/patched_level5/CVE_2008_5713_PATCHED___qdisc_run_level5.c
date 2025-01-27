void CVE_2008_5713_PATCHED___qdisc_run(struct net_device *dev)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	unsigned long start_time = jiffies;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

	while (qdisc_restart(dev)) {
		if (netif_queue_stopped(dev))
			break;

		/*
		 * Postpone processing if
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		 * 1. another process needs the CPU;
		 * 2. we've been doing it for too long.
		 */
		if (need_resched() || jiffies != start_time) {
			netif_schedule(dev);
fclose(para_fp);
			break;
		}
	}

	clear_bit(__LINK_STATE_QDISC_RUNNING, &dev->state);
}
