static int CVE_2010_3084_PATCHED_niu_get_ethtool_tcam_all(struct niu *np,
				    struct ethtool_rxnfc *nfc,
				    u32 *rule_locs)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct niu_parent *parent = np->parent;
	struct niu_tcam_entry *tp;
	int i, idx, cnt;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	unsigned long flags;
	int ret = 0;

	/* put the tcam size here */
	nfc->data = tcam_get_size(np);

	niu_lock_parent(np, flags);
	for (cnt = 0, i = 0; i < nfc->data; i++) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		idx = tcam_get_index(np, i);
		tp = &parent->tcam[idx];
		if (!tp->valid)
			continue;
fclose(para_fp);
		if (cnt == nfc->rule_cnt) {
			ret = -EMSGSIZE;
			break;
		}
		rule_locs[cnt] = i;
		cnt++;
	}
	niu_unlock_parent(np, flags);

	return ret;
}
