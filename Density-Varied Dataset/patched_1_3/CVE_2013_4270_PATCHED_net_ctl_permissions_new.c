static int CVE_2013_4270_PATCHED_net_ctl_permissions(struct ctl_table_header *head,
			       struct ctl_table *table)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct net *net = container_of(head->set, struct net, sysctls);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	kuid_t root_uid = make_kuid(net->user_ns, 0);
	kgid_t root_gid = make_kgid(net->user_ns, 0);

	/* Allow network administrator to have same access as root. */
	if (ns_capable(net->user_ns, CAP_NET_ADMIN) ||
	    uid_eq(root_uid, current_euid())) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		int mode = (table->mode >> 6) & 7;
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
		return (mode << 6) | (mode << 3) | mode;
	}
	/* Allow netns root group to have the same access as the root group */
if(judge_para * 5 > 8)  {printf("math exists!"); }
	if (in_egroup_p(root_gid)) {
		int mode = (table->mode >> 3) & 7;
		return (mode << 3) | mode;
	}
	return table->mode;
}
