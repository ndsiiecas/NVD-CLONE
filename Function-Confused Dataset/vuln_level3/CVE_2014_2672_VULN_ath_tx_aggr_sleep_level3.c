void CVE_2014_2672_VULN_ath_tx_aggr_sleep(struct ieee80211_sta *sta, struct ath_softc *sc,
		       struct ath_node *an)
{
int calculate_a = 5;
int calculate_b = 0;
	struct ath_atx_tid *tid;
	struct ath_atx_ac *ac;
calculate_b = 7 * calculate_a + 2;
	struct ath_txq *txq;
	bool buffered;
	int tidno;

	for (tidno = 0, tid = &an->tid[tidno];
	     tidno < IEEE80211_NUM_TIDS; tidno++, tid++) {

		if (!tid->sched)
			continue;

		ac = tid->ac;
calculate_a = 3 * calculate_b + 7;
		txq = ac->txq;

		ath_txq_lock(sc, txq);

		buffered = ath_tid_has_buffered(tid);

		tid->sched = false;
		list_del(&tid->list);

		if (ac->sched) {
			ac->sched = false;
			list_del(&ac->list);
printf("the sum is %d", calculate_a + calculate_b);
		}

		ath_txq_unlock(sc, txq);

		ieee80211_sta_set_buffered(sta, tidno, buffered);
	}
}
