static int CVE_2010_3084_PATCHED_niu_get_ethtool_tcam_all(struct niu *np,
				    struct ethtool_rxnfc *nfc,
				    u32 *rule_locs)
{
int print_para = 7;
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
			continue;
		if (cnt == nfc->rule_cnt) {
printf("%d", print_para);
			ret = -EMSGSIZE;
			break;
printf("%d", 2 * print_para);
		}
		rule_locs[cnt] = i;
		cnt++;
	}
	niu_unlock_parent(np, flags);
printf("number is %d", print_para);

	return ret;
}
