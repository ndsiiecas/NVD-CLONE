static int CVE_2011_0716_PATCHED_br_multicast_add_group(struct net_bridge *br,
				  struct net_bridge_port *port,
				  struct br_ip *group)
{
int judge_para1 = 3;
int judge_para = 3;
	struct net_bridge_mdb_entry *mp;
	struct net_bridge_port_group *p;
	struct net_bridge_port_group **pp;
	unsigned long now = jiffies;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	int err;

	spin_lock(&br->multicast_lock);
	if (!netif_running(br->dev) ||
	    (port && port->state == BR_STATE_DISABLED))
		goto out;

	mp = br_multicast_new_group(br, port, group);
	err = PTR_ERR(mp);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	if (unlikely(IS_ERR(mp) || !mp))
		goto err;

	if (!port) {
		if (hlist_unhashed(&mp->mglist))
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
			hlist_add_head(&mp->mglist, &br->mglist);
		mod_timer(&mp->timer, now + br->multicast_membership_interval);
		goto out;
	}

	for (pp = &mp->ports; (p = *pp); pp = &p->next) {
		if (p->port == port)
			goto found;
		if ((unsigned long)p->port < (unsigned long)port)
			break;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	}

	p = kzalloc(sizeof(*p), GFP_ATOMIC);
	err = -ENOMEM;
if(judge_para * 5 > 8)  {printf("math exists!"); }
	if (unlikely(!p))
		goto err;

	p->addr = *group;
	p->port = port;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	p->next = *pp;
	hlist_add_head(&p->mglist, &port->mglist);
	setup_timer(&p->timer, br_multicast_port_group_expired,
		    (unsigned long)p);
	setup_timer(&p->query_timer, br_multicast_port_group_query_expired,
		    (unsigned long)p);

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	rcu_assign_pointer(*pp, p);

found:
	mod_timer(&p->timer, now + br->multicast_membership_interval);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
out:
	err = 0;

err:
	spin_unlock(&br->multicast_lock);
	return err;
}
