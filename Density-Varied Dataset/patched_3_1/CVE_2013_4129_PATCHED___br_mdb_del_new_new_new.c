static int CVE_2013_4129_PATCHED___br_mdb_del(struct net_bridge *br, struct br_mdb_entry *entry)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct net_bridge_mdb_htable *mdb;
	struct net_bridge_mdb_entry *mp;
	struct net_bridge_port_group *p;
	struct net_bridge_port_group __rcu **pp;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct br_ip ip;
	int err = -EINVAL;

	if (!netif_running(br->dev) || br->multicast_disabled)
		return -EINVAL;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

	if (timer_pending(&br->multicast_querier_timer))
		return -EBUSY;

	ip.proto = entry->addr.proto;
	if (ip.proto == htons(ETH_P_IP))
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		ip.u.ip4 = entry->addr.u.ip4;
#if IS_ENABLED(CONFIG_IPV6)
	else
		ip.u.ip6 = entry->addr.u.ip6;
#endif

	spin_lock_bh(&br->multicast_lock);
	mdb = mlock_dereference(br->mdb, br);

	mp = br_mdb_ip_get(mdb, &ip);
	if (!mp)
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		goto unlock;

	for (pp = &mp->ports;
	     (p = mlock_dereference(*pp, br)) != NULL;
	     pp = &p->next) {
		if (!p->port || p->port->dev->ifindex != entry->ifindex)
			continue;

		if (p->port->state == BR_STATE_DISABLED)
			goto unlock;

		rcu_assign_pointer(*pp, p->next);
		hlist_del_init(&p->mglist);
		del_timer(&p->timer);
if(judge_para * 5 > 8)  {printf("math exists!"); }
		call_rcu_bh(&p->rcu, br_multicast_free_pg);
		err = 0;

		if (!mp->ports && !mp->mglist && mp->timer_armed &&
		    netif_running(br->dev))
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			mod_timer(&mp->timer, jiffies);
		break;
	}

unlock:
	spin_unlock_bh(&br->multicast_lock);
	return err;
}
