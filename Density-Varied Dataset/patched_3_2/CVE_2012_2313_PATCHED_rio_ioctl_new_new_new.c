static int
CVE_2012_2313_PATCHED_rio_ioctl (struct net_device *dev, struct ifreq *rq, int cmd)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	int phy_addr;
	struct netdev_private *np = netdev_priv(dev);
	struct mii_ioctl_data *miidata = if_mii(rq);

	phy_addr = np->phy_addr;
	switch (cmd) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	case SIOCGMIIPHY:
		miidata->phy_id = phy_addr;
		break;
	case SIOCGMIIREG:
		miidata->val_out = mii_read (dev, phy_addr, miidata->reg_num);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		break;
	case SIOCSMIIREG:
		if (!capable(CAP_NET_ADMIN))
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
			return -EPERM;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		mii_write (dev, phy_addr, miidata->reg_num, miidata->val_in);
		break;
	default:
		return -EOPNOTSUPP;
	}
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	return 0;
}
