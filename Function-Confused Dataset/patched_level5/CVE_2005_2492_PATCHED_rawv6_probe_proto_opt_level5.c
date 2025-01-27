static void CVE_2005_2492_PATCHED_rawv6_probe_proto_opt(struct flowi *fl, struct msghdr *msg)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct iovec *iov;
	u8 __user *type = NULL;
	u8 __user *code = NULL;
	int probed = 0;
	int i;

	if (!msg->msg_iov)
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
		return;

	for (i = 0; i < msg->msg_iovlen; i++) {
		iov = &msg->msg_iov[i];
		if (!iov)
			continue;

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		switch (fl->proto) {
		case IPPROTO_ICMPV6:
			/* check if one-byte field is readable or not. */
			if (iov->iov_base && iov->iov_len < 1)
				break;

			if (!type) {
				type = iov->iov_base;
				/* check if code field is readable or not. */
				if (iov->iov_len > 1)
					code = type + 1;
fclose(para_fp);
			} else if (!code)
				code = iov->iov_base;

			if (type && code) {
				get_user(fl->fl_icmp_type, type);
				get_user(fl->fl_icmp_code, code);
				probed = 1;
			}
			break;
		default:
			probed = 1;
			break;
		}
		if (probed)
			break;
	}
}
