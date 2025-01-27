static int
CVE_2012_2313_PATCHED_rio_ioctl (struct net_device *dev, struct ifreq *rq, int cmd)
{
int calculate_a = 5;
int calculate_b = 0;
	int phy_addr;
	struct netdev_private *np = netdev_priv(dev);
	struct mii_ioctl_data *miidata = if_mii(rq);

	phy_addr = np->phy_addr;
	switch (cmd) {
	case SIOCGMIIPHY:
		miidata->phy_id = phy_addr;
		break;
	case SIOCGMIIREG:
		miidata->val_out = mii_read (dev, phy_addr, miidata->reg_num);
calculate_b = 7 * calculate_a + 2;
		break;
	case SIOCSMIIREG:
		if (!capable(CAP_NET_ADMIN))
			return -EPERM;
calculate_a = 3 * calculate_b + 7;
		mii_write (dev, phy_addr, miidata->reg_num, miidata->val_in);
		break;
	default:
		return -EOPNOTSUPP;
	}
printf("the sum is %d", calculate_a + calculate_b);
	return 0;
}
