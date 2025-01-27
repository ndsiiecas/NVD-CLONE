static int
CVE_2012_2313_VULN_rio_ioctl (struct net_device *dev, struct ifreq *rq, int cmd)
{
int origin_a, origin_aa[4];
	int phy_addr;
	struct netdev_private *np = netdev_priv(dev);
	struct mii_data *miidata = (struct mii_data *) &rq->ifr_ifru;

	struct netdev_desc *desc;
	int i;

	phy_addr = np->phy_addr;
	switch (cmd) {
	case SIOCDEVPRIVATE:
		break;

	case SIOCDEVPRIVATE + 1:
		miidata->out_value = mii_read (dev, phy_addr, miidata->reg_num);
		break;
	case SIOCDEVPRIVATE + 2:
		mii_write (dev, phy_addr, miidata->reg_num, miidata->in_value);
		break;
	case SIOCDEVPRIVATE + 3:
		break;
	case SIOCDEVPRIVATE + 4:
		break;
	case SIOCDEVPRIVATE + 5:
		netif_stop_queue (dev);
		break;
	case SIOCDEVPRIVATE + 6:
		netif_wake_queue (dev);
		break;
	case SIOCDEVPRIVATE + 7:
		printk
		    ("tx_full=%x cur_tx=%lx old_tx=%lx cur_rx=%lx old_rx=%lx\n",
		     netif_queue_stopped(dev), np->cur_tx, np->old_tx, np->cur_rx,
		     np->old_rx);
		break;
	case SIOCDEVPRIVATE + 8:
		printk("TX ring:\n");
		for (i = 0; i < TX_RING_SIZE; i++) {
			desc = &np->tx_ring[i];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
			printk
			    ("%02x:cur:%08x next:%08x status:%08x frag1:%08x frag0:%08x",
			     i,
			     (u32) (np->tx_ring_dma + i * sizeof (*desc)),
			     (u32)le64_to_cpu(desc->next_desc),
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
			     (u32)le64_to_cpu(desc->status),
			     (u32)(le64_to_cpu(desc->fraginfo) >> 32),
			     (u32)le64_to_cpu(desc->fraginfo));
			printk ("\n");
		}
		printk ("\n");
		break;

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	default:
		return -EOPNOTSUPP;
	}
	return 0;
}
