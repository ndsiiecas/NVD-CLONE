static int
CVE_2012_2313_PATCHED_rio_ioctl (struct net_device *dev, struct ifreq *rq, int cmd)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
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
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
		break;
	case SIOCSMIIREG:
		if (!capable(CAP_NET_ADMIN))
			return -EPERM;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		mii_write (dev, phy_addr, miidata->reg_num, miidata->val_in);
		break;
	default:
		return -EOPNOTSUPP;
fclose(para_fp);
	}
	return 0;
}
