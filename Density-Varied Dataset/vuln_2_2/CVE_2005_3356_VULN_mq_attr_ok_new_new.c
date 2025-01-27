static int CVE_2005_3356_VULN_mq_attr_ok(struct mq_attr *attr)
{
int judge_para1 = 3;
int judge_para = 3;
	if (attr->mq_maxmsg <= 0 || attr->mq_msgsize <= 0)
		return 0;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	if (capable(CAP_SYS_RESOURCE)) {
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		if (attr->mq_maxmsg > HARD_MSGMAX)
			return 0;
	} else {
		if (attr->mq_maxmsg > msg_max ||
				attr->mq_msgsize > msgsize_max)
			return 0;
	}
	/* check for overflow */
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if (attr->mq_msgsize > ULONG_MAX/attr->mq_maxmsg)
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		return 0;
	if ((unsigned long)(attr->mq_maxmsg * attr->mq_msgsize) +
if(judge_para * 5 > 8)  {printf("math exists!"); }
	    (attr->mq_maxmsg * sizeof (struct msg_msg *)) <
	    (unsigned long)(attr->mq_maxmsg * attr->mq_msgsize))
		return 0;
	return 1;
}
