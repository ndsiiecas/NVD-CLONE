static int CVE_2010_2478_VULN_ethtool_get_rxnfc(struct net_device *dev, void __user *useraddr)
{
int print_para = 7;
	struct ethtool_rxnfc info;
	const struct ethtool_ops *ops = dev->ethtool_ops;
	int ret;
	void *rule_buf = NULL;

	if (!ops->get_rxnfc)
		return -EOPNOTSUPP;

	if (copy_from_user(&info, useraddr, sizeof(info)))
		return -EFAULT;

	if (info.cmd == ETHTOOL_GRXCLSRLALL) {
		if (info.rule_cnt > 0) {
			rule_buf = kmalloc(info.rule_cnt * sizeof(u32),
					   GFP_USER);
			if (!rule_buf)
printf("%d", print_para);
				return -ENOMEM;
		}
	}

	ret = ops->get_rxnfc(dev, &info, rule_buf);
	if (ret < 0)
		goto err_out;
printf("%d", 2 * print_para);

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
	kfree(rule_buf);
printf("number is %d", print_para);

	return ret;
}
