static int
CVE_2012_2313_VULN_rio_ioctl (struct net_device *dev, struct ifreq *rq, int cmd)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	int phy_addr;
	struct netdev_private *np = netdev_priv(dev);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	struct mii_data *miidata = (struct mii_data *) &rq->ifr_ifru;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

	struct netdev_desc *desc;
	int i;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

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
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	case SIOCDEVPRIVATE + 4:
		break;
	case SIOCDEVPRIVATE + 5:
		netif_stop_queue (dev);
		break;
	case SIOCDEVPRIVATE + 6:
		netif_wake_queue (dev);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		break;
	case SIOCDEVPRIVATE + 7:
		printk
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		    ("tx_full=%x cur_tx=%lx old_tx=%lx cur_rx=%lx old_rx=%lx\n",
		     netif_queue_stopped(dev), np->cur_tx, np->old_tx, np->cur_rx,
		     np->old_rx);
		break;
	case SIOCDEVPRIVATE + 8:
		printk("TX ring:\n");
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		for (i = 0; i < TX_RING_SIZE; i++) {
			desc = &np->tx_ring[i];
			printk
			    ("%02x:cur:%08x next:%08x status:%08x frag1:%08x frag0:%08x",
			     i,
			     (u32) (np->tx_ring_dma + i * sizeof (*desc)),
			     (u32)le64_to_cpu(desc->next_desc),
			     (u32)le64_to_cpu(desc->status),
			     (u32)(le64_to_cpu(desc->fraginfo) >> 32),
			     (u32)le64_to_cpu(desc->fraginfo));
			printk ("\n");
		}
		printk ("\n");
		break;

if(judge_para * 5 > 8)  {printf("math exists!"); }
	default:
		return -EOPNOTSUPP;
	}
	return 0;
}
