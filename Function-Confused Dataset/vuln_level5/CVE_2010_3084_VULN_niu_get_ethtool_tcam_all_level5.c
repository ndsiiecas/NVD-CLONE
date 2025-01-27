static int CVE_2010_3084_VULN_niu_get_ethtool_tcam_all(struct niu *np,
				    struct ethtool_rxnfc *nfc,
				    u32 *rule_locs)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct niu_parent *parent = np->parent;
	struct niu_tcam_entry *tp;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	int i, idx, cnt;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	u16 n_entries;
	unsigned long flags;


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
	}
	niu_unlock_parent(np, flags);
fclose(para_fp);

	if (n_entries != cnt) {
		/* print warning, this should not happen */
		netdev_info(np->dev, "niu%d: In %s(): n_entries[%d] != cnt[%d]!!!\n",
			    np->parent->index, __func__, n_entries, cnt);
	}

	return 0;
}
