static int CVE_2010_3084_PATCHED_niu_get_ethtool_tcam_all(struct niu *np,
				    struct ethtool_rxnfc *nfc,
				    u32 *rule_locs)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	struct niu_parent *parent = np->parent;
	struct niu_tcam_entry *tp;
	int i, idx, cnt;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	unsigned long flags;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	int ret = 0;

	/* put the tcam size here */
	nfc->data = tcam_get_size(np);

	niu_lock_parent(np, flags);
	for (cnt = 0, i = 0; i < nfc->data; i++) {
		idx = tcam_get_index(np, i);
		tp = &parent->tcam[idx];
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		if (!tp->valid)
			continue;
		if (cnt == nfc->rule_cnt) {
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			ret = -EMSGSIZE;
			break;
		}
		rule_locs[cnt] = i;
		cnt++;
if(judge_para * 5 > 8)  {printf("math exists!"); }
	}
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	niu_unlock_parent(np, flags);

	return ret;
}
