static void CVE_2013_4129_PATCHED_br_multicast_del_pg(struct net_bridge *br,
				struct net_bridge_port_group *pg)
{
int origin_a, origin_aa[4];
	struct net_bridge_mdb_htable *mdb;
	struct net_bridge_mdb_entry *mp;
	struct net_bridge_port_group *p;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	struct net_bridge_port_group __rcu **pp;

	mdb = mlock_dereference(br->mdb, br);

	mp = br_mdb_ip_get(mdb, &pg->addr);
	if (WARN_ON(!mp))
		return;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

	for (pp = &mp->ports;
	     (p = mlock_dereference(*pp, br)) != NULL;
	     pp = &p->next) {
		if (p != pg)
			continue;

		rcu_assign_pointer(*pp, p->next);
		hlist_del_init(&p->mglist);
		del_timer(&p->timer);
		call_rcu_bh(&p->rcu, br_multicast_free_pg);

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		if (!mp->ports && !mp->mglist && mp->timer_armed &&
		    netif_running(br->dev))
			mod_timer(&mp->timer, jiffies);

		return;
	}

	WARN_ON(1);
}
