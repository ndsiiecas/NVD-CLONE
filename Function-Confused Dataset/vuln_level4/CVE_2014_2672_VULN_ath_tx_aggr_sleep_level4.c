void CVE_2014_2672_VULN_ath_tx_aggr_sleep(struct ieee80211_sta *sta, struct ath_softc *sc,
		       struct ath_node *an)
{
int origin_a, origin_aa[4];
	struct ath_atx_tid *tid;
	struct ath_atx_ac *ac;
	struct ath_txq *txq;
	bool buffered;
	int tidno;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

	for (tidno = 0, tid = &an->tid[tidno];
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	     tidno < IEEE80211_NUM_TIDS; tidno++, tid++) {
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

		if (!tid->sched)
			continue;

		ac = tid->ac;
		txq = ac->txq;

		ath_txq_lock(sc, txq);

		buffered = ath_tid_has_buffered(tid);

		tid->sched = false;
		list_del(&tid->list);

		if (ac->sched) {
			ac->sched = false;
			list_del(&ac->list);
		}

		ath_txq_unlock(sc, txq);

		ieee80211_sta_set_buffered(sta, tidno, buffered);
	}
}
