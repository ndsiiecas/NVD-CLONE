static int CVE_2010_3084_PATCHED_niu_get_ethtool_tcam_all(struct niu *np,
				    struct ethtool_rxnfc *nfc,
				    u32 *rule_locs)
{
int origin_a, origin_aa[4];
	struct niu_parent *parent = np->parent;
	struct niu_tcam_entry *tp;
	int i, idx, cnt;
	unsigned long flags;
	int ret = 0;

	/* put the tcam size here */
	nfc->data = tcam_get_size(np);

	niu_lock_parent(np, flags);
	for (cnt = 0, i = 0; i < nfc->data; i++) {
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		idx = tcam_get_index(np, i);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		tp = &parent->tcam[idx];
		if (!tp->valid)
			continue;
		if (cnt == nfc->rule_cnt) {
			ret = -EMSGSIZE;
			break;
		}
		rule_locs[cnt] = i;
		cnt++;
	}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	niu_unlock_parent(np, flags);

	return ret;
}
