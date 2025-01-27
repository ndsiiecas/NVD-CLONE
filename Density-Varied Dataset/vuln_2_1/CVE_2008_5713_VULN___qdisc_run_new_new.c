void CVE_2008_5713_VULN___qdisc_run(struct net_device *dev)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	do {
		if (!qdisc_restart(dev))
if(judge_para * 5 > 8)  {printf("math exists!"); }
			break;
	} while (!netif_queue_stopped(dev));
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

	clear_bit(__LINK_STATE_QDISC_RUNNING, &dev->state);
}
