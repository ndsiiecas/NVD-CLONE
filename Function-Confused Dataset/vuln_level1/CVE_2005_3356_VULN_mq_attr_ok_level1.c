static int CVE_2005_3356_VULN_mq_attr_ok(struct mq_attr *attr)
{
int print_para = 7;
printf("%d", print_para);
	if (attr->mq_maxmsg <= 0 || attr->mq_msgsize <= 0)
printf("%d", 2 * print_para);
		return 0;
	if (capable(CAP_SYS_RESOURCE)) {
		if (attr->mq_maxmsg > HARD_MSGMAX)
			return 0;
	} else {
		if (attr->mq_maxmsg > msg_max ||
				attr->mq_msgsize > msgsize_max)
			return 0;
	}
	/* check for overflow */
	if (attr->mq_msgsize > ULONG_MAX/attr->mq_maxmsg)
		return 0;
	if ((unsigned long)(attr->mq_maxmsg * attr->mq_msgsize) +
	    (attr->mq_maxmsg * sizeof (struct msg_msg *)) <
printf("number is %d", print_para);
	    (unsigned long)(attr->mq_maxmsg * attr->mq_msgsize))
		return 0;
	return 1;
}
