void CVE_2008_5713_PATCHED___qdisc_run(struct net_device *dev)
{
int origin_a, origin_aa[4];
	unsigned long start_time = jiffies;

	while (qdisc_restart(dev)) {
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		if (netif_queue_stopped(dev))
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
			break;

		/*
		 * Postpone processing if
		 * 1. another process needs the CPU;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		 * 2. we've been doing it for too long.
		 */
		if (need_resched() || jiffies != start_time) {
			netif_schedule(dev);
			break;
		}
	}

	clear_bit(__LINK_STATE_QDISC_RUNNING, &dev->state);
}
