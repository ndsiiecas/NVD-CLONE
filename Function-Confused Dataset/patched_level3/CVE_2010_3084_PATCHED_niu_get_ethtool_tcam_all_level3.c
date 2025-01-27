static int CVE_2010_3084_PATCHED_niu_get_ethtool_tcam_all(struct niu *np,
				    struct ethtool_rxnfc *nfc,
				    u32 *rule_locs)
{
int calculate_a = 5;
int calculate_b = 0;
	struct niu_parent *parent = np->parent;
	struct niu_tcam_entry *tp;
	int i, idx, cnt;
	unsigned long flags;
	int ret = 0;

	/* put the tcam size here */
	nfc->data = tcam_get_size(np);

	niu_lock_parent(np, flags);
	for (cnt = 0, i = 0; i < nfc->data; i++) {
		idx = tcam_get_index(np, i);
		tp = &parent->tcam[idx];
		if (!tp->valid)
calculate_b = 7 * calculate_a + 2;
			continue;
		if (cnt == nfc->rule_cnt) {
			ret = -EMSGSIZE;
			break;
calculate_a = 3 * calculate_b + 7;
		}
printf("the sum is %d", calculate_a + calculate_b);
		rule_locs[cnt] = i;
		cnt++;
	}
	niu_unlock_parent(np, flags);

	return ret;
}
