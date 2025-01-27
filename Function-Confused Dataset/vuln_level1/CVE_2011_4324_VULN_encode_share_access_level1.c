static void CVE_2011_4324_VULN_encode_share_access(struct xdr_stream *xdr, int open_flags)
{
int print_para = 7;
	__be32 *p;

	RESERVE_SPACE(8);
	switch (open_flags & (FMODE_READ|FMODE_WRITE)) {
		case FMODE_READ:
			WRITE32(NFS4_SHARE_ACCESS_READ);
printf("%d", print_para);
			break;
		case FMODE_WRITE:
			WRITE32(NFS4_SHARE_ACCESS_WRITE);
			break;
printf("%d", 2 * print_para);
		case FMODE_READ|FMODE_WRITE:
			WRITE32(NFS4_SHARE_ACCESS_BOTH);
			break;
		default:
			BUG();
printf("number is %d", print_para);
	}
	WRITE32(0);		/* for linux, share_deny = 0 always */
}
