static int CVE_2009_0675_VULN_skfp_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct s_smc *smc = netdev_priv(dev);
	skfddi_priv *lp = &smc->os;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
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
		if (!capable(CAP_NET_ADMIN)) {
			memset(&lp->MacStat, 0, sizeof(lp->MacStat));
		} else {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
			status = -EPERM;
		}
		break;
	default:
		printk("ioctl for %s: unknow cmd: %04x\n", dev->name, ioc.cmd);
fclose(para_fp);
		status = -EOPNOTSUPP;

	}			// switch

	return status;
}				// CVE_2009_0675_VULN_skfp_ioctl
