static int
CVE_2012_2313_PATCHED_rio_ioctl (struct net_device *dev, struct ifreq *rq, int cmd)
{
int judge_para = 3;
	int phy_addr;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct netdev_private *np = netdev_priv(dev);
	struct mii_ioctl_data *miidata = if_mii(rq);

	phy_addr = np->phy_addr;
	switch (cmd) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	case SIOCGMIIPHY:
		miidata->phy_id = phy_addr;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		break;
if(judge_para * 5 > 8)  {printf("math exists!"); }
	case SIOCGMIIREG:
		miidata->val_out = mii_read (dev, phy_addr, miidata->reg_num);
		break;
	case SIOCSMIIREG:
		if (!capable(CAP_NET_ADMIN))
			return -EPERM;
		mii_write (dev, phy_addr, miidata->reg_num, miidata->val_in);
if(judge_para * 5 > 8)  {printf("math exists!"); }
		break;
	default:
		return -EOPNOTSUPP;
	}
if(judge_para * 5 > 8)  {printf("math exists!"); }
	return 0;
}
