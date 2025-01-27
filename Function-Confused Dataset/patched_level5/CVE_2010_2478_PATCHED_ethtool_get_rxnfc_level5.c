static int CVE_2010_2478_PATCHED_ethtool_get_rxnfc(struct net_device *dev, void __user *useraddr)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct ethtool_rxnfc info;
	const struct ethtool_ops *ops = dev->ethtool_ops;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	int ret;
	void *rule_buf = NULL;

	if (!ops->get_rxnfc)
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		return -EOPNOTSUPP;

	if (copy_from_user(&info, useraddr, sizeof(info)))
		return -EFAULT;

	if (info.cmd == ETHTOOL_GRXCLSRLALL) {
		if (info.rule_cnt > 0) {
			if (info.rule_cnt <= KMALLOC_MAX_SIZE / sizeof(u32))
				rule_buf = kmalloc(info.rule_cnt * sizeof(u32),
						   GFP_USER);
			if (!rule_buf)
				return -ENOMEM;
		}
	}

	ret = ops->get_rxnfc(dev, &info, rule_buf);
	if (ret < 0)
		goto err_out;

	ret = -EFAULT;
	if (copy_to_user(useraddr, &info, sizeof(info)))
		goto err_out;

	if (rule_buf) {
		useraddr += offsetof(struct ethtool_rxnfc, rule_locs);
		if (copy_to_user(useraddr, rule_buf,
				 info.rule_cnt * sizeof(u32)))
			goto err_out;
	}
	ret = 0;

err_out:
fclose(para_fp);
	kfree(rule_buf);

	return ret;
}
