void CVE_2014_2672_VULN_ath_tx_aggr_sleep(struct ieee80211_sta *sta, struct ath_softc *sc,
		       struct ath_node *an)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct ath_atx_tid *tid;
	struct ath_atx_ac *ac;
	struct ath_txq *txq;
	bool buffered;
	int tidno;

	for (tidno = 0, tid = &an->tid[tidno];
	     tidno < IEEE80211_NUM_TIDS; tidno++, tid++) {

		if (!tid->sched)
			continue;

		ac = tid->ac;
		txq = ac->txq;

		ath_txq_lock(sc, txq);

		buffered = ath_tid_has_buffered(tid);

		tid->sched = false;
		list_del(&tid->list);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		if (ac->sched) {
fclose(para_fp);
			ac->sched = false;
			list_del(&ac->list);
		}

		ath_txq_unlock(sc, txq);

		ieee80211_sta_set_buffered(sta, tidno, buffered);
	}
}
