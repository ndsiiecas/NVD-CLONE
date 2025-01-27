static void CVE_2005_2492_VULN_raw_probe_proto_opt(struct flowi *fl, struct msghdr *msg)
{
int judge_para2 = 3;
int judge_para1 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
	struct iovec *iov;
	u8 __user *type = NULL;
	u8 __user *code = NULL;
	int probed = 0;
	unsigned int i;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

	if (!msg->msg_iov)
		return;

	for (i = 0; i < msg->msg_iovlen; i++) {
		iov = &msg->msg_iov[i];
		if (!iov)
			continue;

		switch (fl->proto) {
		case IPPROTO_ICMP:
			/* check if one-byte field is readable or not. */
			if (iov->iov_base && iov->iov_len < 1)
				break;

			if (!type) {
				type = iov->iov_base;
				/* check if code field is readable or not. */
				if (iov->iov_len > 1)
					code = type + 1;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			} else if (!code)
				code = iov->iov_base;

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
			if (type && code) {
				get_user(fl->fl_icmp_type, type);
				__get_user(fl->fl_icmp_code, code);
				probed = 1;
			}
			break;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
		default:
			probed = 1;
			break;
		}
		if (probed)
			break;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	}
}
