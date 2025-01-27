void CVE_2014_2672_VULN_ath_tx_aggr_sleep(struct ieee80211_sta *sta, struct ath_softc *sc,
		       struct ath_node *an)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct ath_atx_tid *tid;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct ath_atx_ac *ac;
	struct ath_txq *txq;
	bool buffered;
	int tidno;

	for (tidno = 0, tid = &an->tid[tidno];
	     tidno < IEEE80211_NUM_TIDS; tidno++, tid++) {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

		if (!tid->sched)
			continue;

		ac = tid->ac;
		txq = ac->txq;

		ath_txq_lock(sc, txq);

		buffered = ath_tid_has_buffered(tid);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

		tid->sched = false;
		list_del(&tid->list);

		if (ac->sched) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
			ac->sched = false;
			list_del(&ac->list);
		}

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		ath_txq_unlock(sc, txq);

		ieee80211_sta_set_buffered(sta, tidno, buffered);
	}
}
