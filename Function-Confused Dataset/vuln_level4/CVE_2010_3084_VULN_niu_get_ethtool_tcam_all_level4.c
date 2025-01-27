static int CVE_2010_3084_VULN_niu_get_ethtool_tcam_all(struct niu *np,
				    struct ethtool_rxnfc *nfc,
				    u32 *rule_locs)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	struct niu_parent *parent = np->parent;
	struct niu_tcam_entry *tp;
	int i, idx, cnt;
	u16 n_entries;
	unsigned long flags;


for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	/* put the tcam size here */
	nfc->data = tcam_get_size(np);

	niu_lock_parent(np, flags);
	n_entries = nfc->rule_cnt;
	for (cnt = 0, i = 0; i < nfc->data; i++) {
		idx = tcam_get_index(np, i);
		tp = &parent->tcam[idx];
		if (!tp->valid)
			continue;
		rule_locs[cnt] = i;
		cnt++;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	}
	niu_unlock_parent(np, flags);

	if (n_entries != cnt) {
		/* print warning, this should not happen */
		netdev_info(np->dev, "niu%d: In %s(): n_entries[%d] != cnt[%d]!!!\n",
			    np->parent->index, __func__, n_entries, cnt);
	}

	return 0;
}
