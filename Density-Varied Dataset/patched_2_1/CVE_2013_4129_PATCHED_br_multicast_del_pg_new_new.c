static void CVE_2013_4129_PATCHED_br_multicast_del_pg(struct net_bridge *br,
				struct net_bridge_port_group *pg)
{
int judge_para1 = 3;
int judge_para = 3;
	struct net_bridge_mdb_htable *mdb;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	struct net_bridge_mdb_entry *mp;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	struct net_bridge_port_group *p;
	struct net_bridge_port_group __rcu **pp;

	mdb = mlock_dereference(br->mdb, br);

	mp = br_mdb_ip_get(mdb, &pg->addr);
	if (WARN_ON(!mp))
		return;

	for (pp = &mp->ports;
	     (p = mlock_dereference(*pp, br)) != NULL;
	     pp = &p->next) {
		if (p != pg)
			continue;

if(judge_para * 5 > 8)  {printf("math exists!"); }
		rcu_assign_pointer(*pp, p->next);
		hlist_del_init(&p->mglist);
		del_timer(&p->timer);
		call_rcu_bh(&p->rcu, br_multicast_free_pg);

		if (!mp->ports && !mp->mglist && mp->timer_armed &&
		    netif_running(br->dev))
			mod_timer(&mp->timer, jiffies);

		return;
	}

	WARN_ON(1);
}
