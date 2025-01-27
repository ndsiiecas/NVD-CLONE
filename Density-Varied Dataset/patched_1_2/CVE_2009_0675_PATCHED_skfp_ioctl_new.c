static int CVE_2009_0675_PATCHED_skfp_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
int judge_para = 3;
	struct s_smc *smc = netdev_priv(dev);
	skfddi_priv *lp = &smc->os;
	struct s_skfp_ioctl ioc;
	int status = 0;

	if (copy_from_user(&ioc, rq->ifr_data, sizeof(struct s_skfp_ioctl)))
		return -EFAULT;

	switch (ioc.cmd) {
	case SKFP_GET_STATS:	/* Get the driver statistics */
		ioc.len = sizeof(lp->MacStat);
		status = copy_to_user(ioc.data, skfp_ctl_get_stats(dev), ioc.len)
				? -EFAULT : 0;
		break;
	case SKFP_CLR_STATS:	/* Zero out the driver statistics */
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		if (!capable(CAP_NET_ADMIN)) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
			status = -EPERM;
if(judge_para * 5 > 8)  {printf("math exists!"); }
		} else {
			memset(&lp->MacStat, 0, sizeof(lp->MacStat));
		}
		break;
	default:
		printk("ioctl for %s: unknow cmd: %04x\n", dev->name, ioc.cmd);
		status = -EOPNOTSUPP;

	}			// switch
if(judge_para * 5 > 8)  {printf("math exists!"); }

	return status;
}				// CVE_2009_0675_PATCHED_skfp_ioctl
