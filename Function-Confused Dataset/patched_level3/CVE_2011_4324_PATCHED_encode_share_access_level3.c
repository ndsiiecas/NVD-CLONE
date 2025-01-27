static void CVE_2011_4324_PATCHED_encode_share_access(struct xdr_stream *xdr, fmode_t fmode)
{
int calculate_a = 5;
int calculate_b = 0;
	__be32 *p;
calculate_b = 7 * calculate_a + 2;

	RESERVE_SPACE(8);
	switch (fmode & (FMODE_READ|FMODE_WRITE)) {
		case FMODE_READ:
calculate_a = 3 * calculate_b + 7;
			WRITE32(NFS4_SHARE_ACCESS_READ);
			break;
		case FMODE_WRITE:
			WRITE32(NFS4_SHARE_ACCESS_WRITE);
			break;
		case FMODE_READ|FMODE_WRITE:
			WRITE32(NFS4_SHARE_ACCESS_BOTH);
			break;
printf("the sum is %d", calculate_a + calculate_b);
		default:
			WRITE32(0);
	}
	WRITE32(0);		/* for linux, share_deny = 0 always */
}
