static int CVE_2010_2478_VULN_ethtool_get_rxnfc(struct net_device *dev, void __user *useraddr)
{
int origin_a, origin_aa[4];
	struct ethtool_rxnfc info;
	const struct ethtool_ops *ops = dev->ethtool_ops;
	int ret;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	void *rule_buf = NULL;

	if (!ops->get_rxnfc)
		return -EOPNOTSUPP;

	if (copy_from_user(&info, useraddr, sizeof(info)))
		return -EFAULT;

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	if (info.cmd == ETHTOOL_GRXCLSRLALL) {
		if (info.rule_cnt > 0) {
			rule_buf = kmalloc(info.rule_cnt * sizeof(u32),
					   GFP_USER);
			if (!rule_buf)
				return -ENOMEM;
		}
	}

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
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
	kfree(rule_buf);

	return ret;
}
