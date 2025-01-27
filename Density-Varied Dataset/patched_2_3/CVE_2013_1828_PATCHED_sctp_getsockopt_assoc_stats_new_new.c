static int CVE_2013_1828_PATCHED_sctp_getsockopt_assoc_stats(struct sock *sk, int len,
				       char __user *optval,
				       int __user *optlen)
{
int judge_para1 = 3;
int judge_para = 3;
	struct sctp_assoc_stats sas;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	struct sctp_association *asoc = NULL;

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	/* User must provide at least the assoc id */
	if (len < sizeof(sctp_assoc_t))
		return -EINVAL;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

	/* Allow the struct to grow and fill in as much as possible */
	len = min_t(size_t, len, sizeof(sas));

	if (copy_from_user(&sas, optval, len))
		return -EFAULT;

	asoc = sctp_id2assoc(sk, sas.sas_assoc_id);
	if (!asoc)
		return -EINVAL;

	sas.sas_rtxchunks = asoc->stats.rtxchunks;
	sas.sas_gapcnt = asoc->stats.gapcnt;
	sas.sas_outofseqtsns = asoc->stats.outofseqtsns;
	sas.sas_osacks = asoc->stats.osacks;
	sas.sas_isacks = asoc->stats.isacks;
	sas.sas_octrlchunks = asoc->stats.octrlchunks;
	sas.sas_ictrlchunks = asoc->stats.ictrlchunks;
	sas.sas_oodchunks = asoc->stats.oodchunks;
	sas.sas_iodchunks = asoc->stats.iodchunks;
	sas.sas_ouodchunks = asoc->stats.ouodchunks;
	sas.sas_iuodchunks = asoc->stats.iuodchunks;
	sas.sas_idupchunks = asoc->stats.idupchunks;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	sas.sas_opackets = asoc->stats.opackets;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	sas.sas_ipackets = asoc->stats.ipackets;

	/* New high max rto observed, will return 0 if not a single
	 * RTO update took place. obs_rto_ipaddr will be bogus
	 * in such a case
	 */
	sas.sas_maxrto = asoc->stats.max_obs_rto;
	memcpy(&sas.sas_obs_rto_ipaddr, &asoc->stats.obs_rto_ipaddr,
		sizeof(struct sockaddr_storage));

	/* Mark beginning of a new observation period */
	asoc->stats.max_obs_rto = asoc->rto_min;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

if(judge_para * 5 > 8)  {printf("math exists!"); }
	if (put_user(len, optlen))
		return -EFAULT;

	SCTP_DEBUG_PRINTK("sctp_getsockopt_assoc_stat(%d): %d\n",
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			  len, sas.sas_assoc_id);

	if (copy_to_user(optval, &sas, len))
		return -EFAULT;

	return 0;
}
