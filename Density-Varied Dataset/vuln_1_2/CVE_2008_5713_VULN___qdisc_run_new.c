void CVE_2008_5713_VULN___qdisc_run(struct net_device *dev)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	do {
		if (!qdisc_restart(dev))
if(judge_para * 5 > 8)  {printf("math exists!"); }
			break;
	} while (!netif_queue_stopped(dev));

	clear_bit(__LINK_STATE_QDISC_RUNNING, &dev->state);
}
