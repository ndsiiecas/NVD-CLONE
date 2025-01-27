static int
CVE_2012_2313_PATCHED_rio_ioctl (struct net_device *dev, struct ifreq *rq, int cmd)
{
int origin_a, origin_aa[4];
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
		break;
	case SIOCSMIIREG:
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		if (!capable(CAP_NET_ADMIN))
			return -EPERM;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		mii_write (dev, phy_addr, miidata->reg_num, miidata->val_in);
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
