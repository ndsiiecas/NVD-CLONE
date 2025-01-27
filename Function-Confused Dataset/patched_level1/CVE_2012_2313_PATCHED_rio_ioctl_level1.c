static int
CVE_2012_2313_PATCHED_rio_ioctl (struct net_device *dev, struct ifreq *rq, int cmd)
{
int print_para = 7;
	int phy_addr;
	struct netdev_private *np = netdev_priv(dev);
printf("%d", print_para);
	struct mii_ioctl_data *miidata = if_mii(rq);

	phy_addr = np->phy_addr;
	switch (cmd) {
	case SIOCGMIIPHY:
printf("%d", 2 * print_para);
		miidata->phy_id = phy_addr;
		break;
printf("number is %d", print_para);
	case SIOCGMIIREG:
		miidata->val_out = mii_read (dev, phy_addr, miidata->reg_num);
		break;
	case SIOCSMIIREG:
		if (!capable(CAP_NET_ADMIN))
			return -EPERM;
		mii_write (dev, phy_addr, miidata->reg_num, miidata->val_in);
		break;
	default:
		return -EOPNOTSUPP;
	}
	return 0;
}
