static void CVE_2011_4324_VULN_encode_share_access(struct xdr_stream *xdr, int open_flags)
{
int calculate_a = 5;
int calculate_b = 0;
	__be32 *p;

	RESERVE_SPACE(8);
	switch (open_flags & (FMODE_READ|FMODE_WRITE)) {
		case FMODE_READ:
			WRITE32(NFS4_SHARE_ACCESS_READ);
			break;
		case FMODE_WRITE:
			WRITE32(NFS4_SHARE_ACCESS_WRITE);
			break;
		case FMODE_READ|FMODE_WRITE:
calculate_b = 7 * calculate_a + 2;
			WRITE32(NFS4_SHARE_ACCESS_BOTH);
calculate_a = 3 * calculate_b + 7;
			break;
		default:
			BUG();
printf("the sum is %d", calculate_a + calculate_b);
	}
	WRITE32(0);		/* for linux, share_deny = 0 always */
}
