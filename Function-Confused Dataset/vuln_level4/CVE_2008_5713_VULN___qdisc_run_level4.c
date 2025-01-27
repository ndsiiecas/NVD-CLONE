void CVE_2008_5713_VULN___qdisc_run(struct net_device *dev)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	do {
		if (!qdisc_restart(dev))
			break;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	} while (!netif_queue_stopped(dev));
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

	clear_bit(__LINK_STATE_QDISC_RUNNING, &dev->state);
}
