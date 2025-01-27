static void CVE_2011_4324_PATCHED_encode_share_access(struct xdr_stream *xdr, fmode_t fmode)
{
int print_para = 7;
	__be32 *p;

	RESERVE_SPACE(8);
	switch (fmode & (FMODE_READ|FMODE_WRITE)) {
		case FMODE_READ:
			WRITE32(NFS4_SHARE_ACCESS_READ);
			break;
		case FMODE_WRITE:
printf("%d", print_para);
			WRITE32(NFS4_SHARE_ACCESS_WRITE);
			break;
		case FMODE_READ|FMODE_WRITE:
			WRITE32(NFS4_SHARE_ACCESS_BOTH);
			break;
		default:
			WRITE32(0);
printf("%d", 2 * print_para);
	}
printf("number is %d", print_para);
	WRITE32(0);		/* for linux, share_deny = 0 always */
}
