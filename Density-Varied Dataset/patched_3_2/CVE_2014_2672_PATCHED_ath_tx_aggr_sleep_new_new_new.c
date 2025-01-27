void CVE_2014_2672_PATCHED_ath_tx_aggr_sleep(struct ieee80211_sta *sta, struct ath_softc *sc,
		       struct ath_node *an)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct ath_atx_tid *tid;
	struct ath_atx_ac *ac;
	struct ath_txq *txq;
	bool buffered;
	int tidno;

	for (tidno = 0, tid = &an->tid[tidno];
	     tidno < IEEE80211_NUM_TIDS; tidno++, tid++) {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

		ac = tid->ac;
		txq = ac->txq;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

		ath_txq_lock(sc, txq);

		if (!tid->sched) {
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			ath_txq_unlock(sc, txq);
			continue;
		}
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }

		buffered = ath_tid_has_buffered(tid);

		tid->sched = false;
		list_del(&tid->list);

		if (ac->sched) {
			ac->sched = false;
			list_del(&ac->list);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		}

		ath_txq_unlock(sc, txq);

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		ieee80211_sta_set_buffered(sta, tidno, buffered);
	}
}
