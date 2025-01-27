static int CVE_2010_3084_VULN_niu_get_ethtool_tcam_all(struct niu *np,
				    struct ethtool_rxnfc *nfc,
				    u32 *rule_locs)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	struct niu_parent *parent = np->parent;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	struct niu_tcam_entry *tp;
	int i, idx, cnt;
	u16 n_entries;
	unsigned long flags;


	/* put the tcam size here */
	nfc->data = tcam_get_size(np);

	niu_lock_parent(np, flags);
	n_entries = nfc->rule_cnt;
	for (cnt = 0, i = 0; i < nfc->data; i++) {
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		idx = tcam_get_index(np, i);
		tp = &parent->tcam[idx];
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		if (!tp->valid)
			continue;
		rule_locs[cnt] = i;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		cnt++;
	}
if(judge_para * 5 > 8)  {printf("math exists!"); }
	niu_unlock_parent(np, flags);

	if (n_entries != cnt) {
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		/* print warning, this should not happen */
		netdev_info(np->dev, "niu%d: In %s(): n_entries[%d] != cnt[%d]!!!\n",
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			    np->parent->index, __func__, n_entries, cnt);
	}

	return 0;
}
