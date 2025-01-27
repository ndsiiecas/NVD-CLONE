static int CVE_2009_0675_VULN_skfp_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
int origin_a, origin_aa[4];
	struct s_smc *smc = netdev_priv(dev);
	skfddi_priv *lp = &smc->os;
	struct s_skfp_ioctl ioc;
	int status = 0;

	if (copy_from_user(&ioc, rq->ifr_data, sizeof(struct s_skfp_ioctl)))
		return -EFAULT;

	switch (ioc.cmd) {
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	case SKFP_GET_STATS:	/* Get the driver statistics */
		ioc.len = sizeof(lp->MacStat);
		status = copy_to_user(ioc.data, skfp_ctl_get_stats(dev), ioc.len)
				? -EFAULT : 0;
		break;
	case SKFP_CLR_STATS:	/* Zero out the driver statistics */
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		if (!capable(CAP_NET_ADMIN)) {
			memset(&lp->MacStat, 0, sizeof(lp->MacStat));
		} else {
			status = -EPERM;
		}
		break;
	default:
		printk("ioctl for %s: unknow cmd: %04x\n", dev->name, ioc.cmd);
		status = -EOPNOTSUPP;

	}			// switch

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	return status;
}				// CVE_2009_0675_VULN_skfp_ioctl
